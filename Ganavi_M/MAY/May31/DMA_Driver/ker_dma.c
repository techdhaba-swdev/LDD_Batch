#include <linux/module.h>
#include <linux/init.h>
#include <linux/pci.h>
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include <linux/scatterlist.h>
#include <linux/interrupt.h>

#define DEVICE_NAME "simple_dma"
#define DMA_BUFFER_SIZE PAGE_SIZE

struct simple_dma_dev {
    struct pci_dev *pdev;
    void *cpu_addr;
    dma_addr_t dma_handle;
    struct scatterlist sg;
};

static int simple_dma_probe(struct pci_dev *pdev, const struct pci_device_id *ent);
static void simple_dma_remove(struct pci_dev *pdev);

static struct pci_device_id simple_dma_ids[] = {
    { PCI_DEVICE(PCI_VENDOR_ID_INTEL, PCI_ANY_ID), },
    { 0, }
};

static struct pci_driver simple_dma_driver = {
    .name = DEVICE_NAME,
    .id_table = simple_dma_ids,
    .probe = simple_dma_probe,
    .remove = simple_dma_remove,
};

static int simple_dma_probe(struct pci_dev *pdev, const struct pci_device_id *ent) {
    struct simple_dma_dev *dev;
    int ret;

    dev = kzalloc(sizeof(*dev), GFP_KERNEL);
    if (!dev) {
        dev_err(&pdev->dev, "Cannot allocate memory\n");
        return -ENOMEM;
    }

    dev->pdev = pdev;
    pci_set_drvdata(pdev, dev);

    ret = pci_enable_device(pdev);
    if (ret) {
        dev_err(&pdev->dev, "Cannot enable PCI device\n");
        goto err_free_dev;
    }

    dev->cpu_addr = dma_alloc_coherent(&pdev->dev, DMA_BUFFER_SIZE, &dev->dma_handle, GFP_KERNEL);
    if (!dev->cpu_addr) {
        dev_err(&pdev->dev, "Cannot allocate DMA buffer\n");
        ret = -ENOMEM;
        goto err_disable_device;
    }

    sg_init_table(&dev->sg, 1);
    sg_set_buf(&dev->sg, dev->cpu_addr, DMA_BUFFER_SIZE);
    ret = dma_map_sg(&pdev->dev, &dev->sg, 1, DMA_TO_DEVICE);
    if (!ret) {
        dev_err(&pdev->dev, "Cannot map scatter-gather list\n");
        ret = -ENOMEM;
        goto err_free_dma;
    }

    // Dummy data to DMA buffer
    strcpy(dev->cpu_addr, "Hello DMA");

    // DMA transfer should be initiated here, depending on your hardware specifics

    return 0;

err_free_dma:
    dma_free_coherent(&pdev->dev, DMA_BUFFER_SIZE, dev->cpu_addr, dev->dma_handle);
err_disable_device:
    pci_disable_device(pdev);
err_free_dev:
    kfree(dev);
    return ret;
}

static void simple_dma_remove(struct pci_dev *pdev) {
    struct simple_dma_dev *dev = pci_get_drvdata(pdev);

    dma_unmap_sg(&pdev->dev, &dev->sg, 1, DMA_TO_DEVICE);
    dma_free_coherent(&pdev->dev, DMA_BUFFER_SIZE, dev->cpu_addr, dev->dma_handle);
    pci_disable_device(pdev);
    kfree(dev);
}

static int __init simple_dma_init(void) {
    return pci_register_driver(&simple_dma_driver);
}

static void __exit simple_dma_exit(void) {
    pci_unregister_driver(&simple_dma_driver);
}

module_init(simple_dma_init);
module_exit(simple_dma_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple DMA Driver");
MODULE_AUTHOR("Ganavi");
MODULE_DEVICE_TABLE(pci, simple_dma_ids);
