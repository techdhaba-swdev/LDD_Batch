#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x85df9b6c, "strsep" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x37a0cba, "kfree" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa916b694, "strnlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x69acdf38, "memcpy" },
	{ 0x9166fada, "strncpy" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x6006375e, "__register_chrdev" },
	{ 0xb88db70c, "kmalloc_caches" },
	{ 0x4454730e, "kmalloc_trace" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x122c3a7e, "_printk" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xb02ba1d5, "remap_pfn_range" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xbb4f4766, "simple_write_to_buffer" },
	{ 0x2fa5cadd, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DA86C64CE27645E369D7124");
