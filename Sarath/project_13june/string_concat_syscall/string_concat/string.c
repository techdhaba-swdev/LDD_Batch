#include <linux/kernel.h>
#include <linux/syscalls.h>
#include<linux/printk.h>
SYSCALL_DEFINE0(string_concat)
{
    	printk(KERN_INFO"concating Successfull\n");
	char destination_string[100];
	char source_string1[] = "Hello, ";
	char source_string2[] = "world!";
	int combined_length = snprintf(destination_string, sizeof(destination_string), "%s%s", source_string1, source_source2);
	if (combined_length >= 0) {
  		printk(KERN_INFO "Concatenated string: %s\n", destination_string);
	} else {
  		printk(KERN_ERR "Error during string concatenation\n");
	}
    		return 0;
}
