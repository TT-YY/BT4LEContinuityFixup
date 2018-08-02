//
//  kern_bt4lefx.hpp
//  BT4LEContiunityFixup
//
//  Copyright © 2017 lvs1974. All rights reserved.
//

#ifndef kern_bt4lefx_hpp
#define kern_bt4lefx_hpp

#include <Headers/kern_patcher.hpp>

class BT4LEFX {
public:
	bool init();
	void deinit();
	
private:
	/**
	 *  Patch kext if needed and prepare other patches
	 *
	 *  @param patcher KernelPatcher instance
	 *  @param index   kinfo handle
	 *  @param address kinfo load address
	 *  @param size    kinfo memory size
	 */
	void processKext(KernelPatcher &patcher, size_t index, mach_vm_address_t address, size_t size);

	/**
	 *  Hooked methods / callbacks
	 */
	static int AppleBroadcomBluetoothHostController_SetControllerFeatureFlags(void *that, unsigned int a2);

	/**
	 *  Original method
	 */
	mach_vm_address_t orgIOBluetoothHostController_SetControllerFeatureFlags {};
};

#endif /* kern_bt4lefx_hpp */
