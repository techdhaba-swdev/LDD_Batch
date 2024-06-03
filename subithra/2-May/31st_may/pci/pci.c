#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/pci.h>
#include <linux/io.h>

#define PCI_VENDOR_ID_SAMPLE 0x1234  
#define PCI_DEVICE_ID_SAMPLE 0x5678  

#define DRIVER_NAME "pci_example"

static struct pci_device_id pci_ids[] = {
    { PCI_DEVICE(PCI_VENDOR_ID_SAMPLE, PCI_DEVICE_ID_SAMPLE), },
    { 0, }
};
MODULE_DEVICE_TABLE(pci, pci_ids);

static int pci_probe(struct pci_dev *dev, const struct pci_device_id *id);
static void pci_remove(struct pci_dev *dev);

static struct pci_driver pci_driver = {
    .name = DRIVER_NAME,
    .id_table = pci_ids,
    .probe = pci_probe,
    .remove = pci_remove,
};

static int __init pci_example_init(void)
{
    return pci_register_driver(&pci_driver);
}

static void __exit pci_example_exit(void)
{
    pci_unregister_driver(&pci_driver);
}

// Probe function called when a matching PCI device is found
static int pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
    int err;
    void __iomem *base_addr;

    // Enable PCI device
    err = pci_enable_device(dev);
    if (err) {
        printk(KERN_ERR "pci_example: Failed to enable PCI device\n");
        return err;
    }

    // Request PCI regions
    err = pci_request_regions(dev, DRIVER_NAME);
    if (err) {
        printk(KERN_ERR "pci_example: Failed to request PCI regions\n");
        pci_disable_device(dev);
        return err;
    }

    // Map BAR0 (Base Address Register 0)
    base_addr = pci_iomap(dev, 0, pci_resource_len(dev, 0));
    if (!base_addr) {
        printk(KERN_ERR "pci_example: Failed to map BAR0\n");
        pci_release_regions(dev);
        pci_disable_device(dev);
        return -ENOMEM;
    }

    printk(KERN_INFO "pci_example: Mapped BAR0 at %p\n", base_addr);

    // Example read and write to BAR0
    iowrite32(0xDEADBEEF, base_addr);
    printk(KERN_INFO "pci_example: Wrote 0xDEADBEEF to BAR0\n");
    printk(KERN_INFO "pci_example: Read 0x%X from BAR0\n", ioread32(base_addr));

    pci_iounmap(dev, base_addr);
    pci_release_regions(dev);
    pci_disable_device(dev);

    return 0;
}

// Remove function called when the PCI device is removed
static void pci_remove(struct pci_dev *dev)
{
    printk(KERN_INFO "pci_example: PCI device removed\n");
}

module_init(pci_example_init);
module_exit(pci_example_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("techdhaba");
MODULE_DESCRIPTION("A simple PCI driver example");
MODULE_VERSION("1.0");
