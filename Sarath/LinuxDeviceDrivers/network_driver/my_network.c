#include <linux/module.h>
#include <linux/netdevice.h> //structures and functions related to network driver
#include <linux/etherdevice.h> //provides definitins specific to ethernet devices

static struct net_device *dev; //dev is a pointer to net_device structure
static int my_open(struct net_device *dev) { //for opening a network device
    netif_start_queue(dev); //indicates that device is ready to recieve packets
    return 0; //on success returns 0
}

static int my_stop(struct net_device *dev) { //called when net-dev is closed
    netif_stop_queue(dev); //indicating the device is no longer ready to recieve packets
    return 0; //on success returns 0
}

static netdev_tx_t my_start_xmit(struct sk_buff *skb, struct net_device *dev) { //most imp func which handles packet transmission
	//recieves sk_buff packet and pointer to net-dev i.e ..(dev)
    // Transmission logic here
    dev_kfree_skb(skb); //here we are just freeing the packet
    return NETDEV_TX_OK;
}

static struct net_device_ops netdev_ops = { //network device operation structure
    .ndo_open = my_open,
    .ndo_stop = my_stop,
    .ndo_start_xmit = my_start_xmit,
};
static void my_setup(struct net_device *dev) { //called during device initialization
    ether_setup(dev); //to configure basic ethernet device settings
    dev->netdev_ops = &netdev_ops; //assigns netdev_ops to device net-operation structure
}

static int __init my_init(void) { //called when module is loaded
    dev = alloc_netdev(0, "net%d", NET_NAME_UNKNOWN, my_setup); //allocates memory and setsup the device
    if (register_netdev(dev)) { //registering the device
        printk("Failed to register net device\n");
        return -1; //on failure
    }
    return 0; //on success
}

static void __exit my_exit(void) { //called when module is unloaded
    unregister_netdev(dev); //unregisters the device
    free_netdev(dev); //frees the memory
}

module_init(my_init); //macro which registers init function as initialization function
module_exit(my_exit); //macro which registers exit function as cleanup function

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Experienced Network Driver Developer");
MODULE_DESCRIPTION("A Simple Network Device Driver");
