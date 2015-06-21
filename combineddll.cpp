#include <windows.h>
#include "halide_out_blur.h"

void __cdecl doBlur(uint8_t* input, uint8_t* output, unsigned int width,
		unsigned int height, unsigned int total_image_width, unsigned int output_stride) {
	buffer_t input_buf = {0}, output_buf = {0};
	
	input_buf.extent[0] = width + 2; input_buf.extent[1] = height + 2;
	input_buf.stride[0] = 1; input_buf.stride[1] = total_image_width;
	input_buf.elem_size = 1;
	input_buf.host = input - total_image_width - 1;
	
	output_buf.extent[0] = width; output_buf.extent[1] = height;
	output_buf.stride[0] = 1; output_buf.stride[1] = output_stride;
	output_buf.elem_size = 1;
	output_buf.host = output;

	halide_out_blur(&input_buf, &output_buf);
}

void __declspec(naked) blurTarget() {
	__asm {
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push ecx
	push edx
	push edi
	push esi

	push [ebp+0x1c]
	push [ebp+0x18]
	push [ebp+0x10]
	push [ebp+0x14]
	push [ebp+0x0c]
	push [ebp+0x08]
	call doBlur
	add esp, 24

	pop esi
	pop edi
	pop edx
	pop ecx
	pop ebx
	pop eax
	mov esp, ebp
	pop ebp
	ret
	}
}

#include "halide_out_boxblur.h"

void __cdecl doBoxBlur(uint8_t* input, uint8_t* output, unsigned int width,
		unsigned int height, unsigned int total_image_width, unsigned int output_stride) {
	buffer_t input_buf = {0}, output_buf = {0};
	
	input_buf.extent[0] = width + 2; input_buf.extent[1] = height + 2;
	input_buf.stride[0] = 1; input_buf.stride[1] = total_image_width;
	input_buf.elem_size = 1;
	input_buf.host = input - total_image_width - 1;
	
	output_buf.extent[0] = width; output_buf.extent[1] = height;
	output_buf.stride[0] = 1; output_buf.stride[1] = output_stride;
	output_buf.elem_size = 1;
	output_buf.host = output;

	halide_out_boxblur(1, 2.0, 1.0, &input_buf, &output_buf);
}

void __declspec(naked) boxBlurTarget() {
	__asm {
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push ecx
	push edx
	push edi
	push esi

	push [ebp+0x1c]
	push [ebp+0x18]
	push [ebp+0x10]
	push [ebp+0x14]
	push [ebp+0x0c]
	push [ebp+0x08]
	call doBoxBlur
	add esp, 24

	pop esi
	pop edi
	pop edx
	pop ecx
	pop ebx
	pop eax
	mov esp, ebp
	pop ebp
	ret
	}
}

#include "halide_out_brightness.h"

void __cdecl doBrightness(uint8_t* input, uint8_t* output, unsigned int width,
		unsigned int height, unsigned int input_stride, unsigned int output_stride,
		uint8_t* lookup_table) {
	buffer_t input_buf = {0}, output_buf = {0}, lookup_buf = {0};
	
	input_buf.extent[0] = width; input_buf.extent[1] = height;
	input_buf.stride[0] = 1; input_buf.stride[1] = input_stride;
	input_buf.elem_size = 1;
	input_buf.host = input;
	
	output_buf.extent[0] = width; output_buf.extent[1] = height;
	output_buf.stride[0] = 1; output_buf.stride[1] = output_stride;
	output_buf.elem_size = 1;
	output_buf.host = output;

	lookup_buf.extent[0] = 256; lookup_buf.extent[1] = 1;
	lookup_buf.stride[0] = 1; lookup_buf.stride[1] = 256;
	lookup_buf.elem_size = 1;
	lookup_buf.host = lookup_table;

	halide_out_brightness(&lookup_buf, &input_buf, &output_buf);
}

void __declspec(naked) brightnessTarget() {
	__asm {
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push ecx
	push edx
	push edi
	push esi

	push [ebp+0x20]
	push [ebp+0x1c]
	push [ebp+0x18]
	push [ebp+0x10]
	push [ebp+0x14]
	push [ebp+0x0c]
	push [ebp+0x08]
	call doBrightness
	add esp, 28

	pop esi
	pop edi
	pop edx
	pop ecx
	pop ebx
	pop eax
	mov esp, ebp
	pop ebp
	ret
	}
}

#include "halide_out_despeckle.h"

void __cdecl doDespeckle(uint8_t* input, uint8_t* output, unsigned int width,
		unsigned int height, unsigned int total_image_width, unsigned int output_stride) {
buffer_t input_buf = {0}, output_buf = {0};
	
	input_buf.extent[0] = width + 2; input_buf.extent[1] = height + 2;
	input_buf.stride[0] = 1; input_buf.stride[1] = total_image_width;
	input_buf.elem_size = 1;
	input_buf.host = input - total_image_width - 1;
	
	output_buf.extent[0] = width; output_buf.extent[1] = height;
	output_buf.stride[0] = 1; output_buf.stride[1] = output_stride;
	output_buf.elem_size = 1;
	output_buf.host = output;

	halide_out_despeckle(&input_buf, &output_buf);
}

void __declspec(naked) despeckleTarget() {
	__asm {
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push ecx
	push edx
	push edi
	push esi

	push [ebp+0x1c]
	push [ebp+0x18]
	push [ebp+0x10]
	push [ebp+0x14]
	push [ebp+0x0c]
	push [ebp+0x08]
	call doDespeckle
	add esp, 24

	pop esi
	pop edi
	pop edx
	pop ecx
	pop ebx
	pop eax
	mov esp, ebp
	pop ebp
	ret
	}
}

#include "halide_out_equalize.h"

void __cdecl doEqualize(uint8_t* input, unsigned int width, unsigned int height,
		unsigned int input_stride, uint8_t* histogram) {
	buffer_t input_buf = {0}, output_buf = {0};
	
	input_buf.extent[0] = width; input_buf.extent[1] = height;
	input_buf.stride[0] = 1; input_buf.stride[1] = input_stride;
	input_buf.elem_size = 1;
	input_buf.host = input;
	
	output_buf.extent[0] = 256;
	output_buf.stride[0] = 1;
	output_buf.elem_size = 8;
	output_buf.host = histogram;

	halide_out_equalize(&input_buf, &output_buf);
}

void __declspec(naked) equalizeTarget() {
	__asm {
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push ecx
	push edx
	push edi
	push esi

	push [ebp+0x24]
	push [ebp+0x18]
	push [ebp+0x10]
	push [ebp+0x14]
	push [ebp+0x08]
	call doEqualize
	add esp, 20

	pop esi
	pop edi
	pop edx
	pop ecx
	pop ebx
	pop eax
	mov esp, ebp
	pop ebp
	ret
	}
}

#include "halide_out_invert.h"

void __cdecl doInvert(uint8_t* input, uint8_t* output, unsigned int size) {
	buffer_t input_buf = {0}, output_buf = {0};
	
	unsigned int width = size, height = 1;
	input_buf.extent[0] = width; input_buf.extent[1] = height;
	input_buf.stride[0] = 1; input_buf.stride[1] = width;
	input_buf.elem_size = 1;
	input_buf.host = input;
	
	output_buf.extent[0] = width; output_buf.extent[1] = height;
	output_buf.stride[0] = 1; output_buf.stride[1] = width;
	output_buf.elem_size = 1;
	output_buf.host = output;

	halide_out_invert(&input_buf, &output_buf);
}

void __declspec(naked) invertTarget() {
	__asm {
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push ecx
	push edx
	push edi
	push esi

	push ecx
	push eax
	push [ebp+8]
	call doInvert
	add esp, 12

	pop esi
	pop edi
	pop edx
	pop ecx
	pop ebx
	pop eax
	mov esp, ebp
	pop ebp
	ret
	}
}

void __cdecl doInvertMMX(uint8_t* input, uint8_t* output, unsigned int width,
		unsigned int height, unsigned int input_stride, unsigned int output_stride) {
	buffer_t input_buf = {0}, output_buf = {0};
	
	input_buf.extent[0] = width; input_buf.extent[1] = height;
	input_buf.stride[0] = 1; input_buf.stride[1] = input_stride;
	input_buf.elem_size = 1;
	input_buf.host = input;
	
	output_buf.extent[0] = width; output_buf.extent[1] = height;
	output_buf.stride[0] = 1; output_buf.stride[1] = output_stride;
	output_buf.elem_size = 1;
	output_buf.host = output;

	halide_out_invert(&input_buf, &output_buf);
}

void __declspec(naked) invertMMXTarget() {
	__asm {
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push ecx
	push edx
	push edi
	push esi

	push [ebp+0x1c]
	push [ebp+0x18]
	push [ebp+0x10]
	push [ebp+0x14]
	push [ebp+0x0c]
	push [ebp+0x08]
	call doInvertMMX
	add esp, 24

	pop esi
	pop edi
	pop edx
	pop ecx
	pop ebx
	pop eax
	mov esp, ebp
	pop ebp
	ret
	}
}

#include "halide_out_noise.h"

HANDLE hHeap = 0;

void __cdecl doNoise(uint8_t* input, uint8_t* output, unsigned int width,
		unsigned int height, unsigned int input_stride, unsigned int output_stride,
		uint8_t* table1, uint8_t* table2, unsigned int param1, unsigned int param2) {
	buffer_t input_buf = {0}, output_buf = {0}, table1_buf = {0}, table2_buf = {0};
	
	input_buf.extent[0] = width; input_buf.extent[1] = height;
	input_buf.stride[0] = 1; input_buf.stride[1] = input_stride;
	input_buf.elem_size = 1;
	input_buf.host = input;
	
	output_buf.extent[0] = width; output_buf.extent[1] = height;
	output_buf.stride[0] = 1; output_buf.stride[1] = output_stride;
	output_buf.elem_size = 1;
	output_buf.host = output;

	table1_buf.extent[0] = HeapSize(hHeap, 0, table1) /* 2*65535 + 4*input_stride */; table1_buf.extent[1] = 1;
	table1_buf.stride[0] = 1; table1_buf.stride[1] = 0;
	table1_buf.elem_size = 2;
	table1_buf.host = table1;

	table2_buf.extent[0] = HeapSize(hHeap, 0, table2) /* height */; table2_buf.extent[1] = 1;
	table2_buf.stride[0] = 1; table2_buf.stride[1] = 0;
	table2_buf.elem_size = 2;
	table2_buf.host = table2;

	halide_out_noise(0 /*param2*/, 0/*param1*/, &table1_buf, &table2_buf, &input_buf, &output_buf);
}

void __declspec(naked) noiseTarget() {
	__asm {
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push ecx
	push edx
	push edi
	push esi

	push [ebp+0x2c]
	push [ebp+0x28]
	push [ebp+0x24]
	push [ebp+0x20]
	push [ebp+0x1c]
	push [ebp+0x18]
	push [ebp+0x10]
	push [ebp+0x14]
	push [ebp+0x0c]
	push [ebp+0x08]
	call doNoise
	add esp, 40

	pop esi
	pop edi
	pop edx
	pop ecx
	pop ebx
	pop eax
	mov esp, ebp
	pop ebp
	ret
	}
}


#include "halide_out_sharpen.h"

void __cdecl doSharpen(uint8_t* input, uint8_t* output, unsigned int width,
		unsigned int height, unsigned int total_image_width, unsigned int output_stride) {
buffer_t input_buf = {0}, output_buf = {0};
	
	input_buf.extent[0] = width + 2; input_buf.extent[1] = height + 2;
	input_buf.stride[0] = 1; input_buf.stride[1] = total_image_width;
	input_buf.elem_size = 1;
	input_buf.host = input - total_image_width - 1;
	
	output_buf.extent[0] = width; output_buf.extent[1] = height;
	output_buf.stride[0] = 1; output_buf.stride[1] = output_stride;
	output_buf.elem_size = 1;
	output_buf.host = output;

	halide_out_sharpen(&input_buf, &output_buf);
}

void __declspec(naked) sharpenTarget() {
	__asm {
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push ecx
	push edx
	push edi
	push esi

	push [ebp+0x1c]
	push [ebp+0x18]
	push [ebp+0x10]
	push [ebp+0x14]
	push [ebp+0x0c]
	push [ebp+0x08]
	call doSharpen
	add esp, 24

	pop esi
	pop edi
	pop edx
	pop ecx
	pop ebx
	pop eax
	mov esp, ebp
	pop ebp
	ret
	}
}

#include "halide_out_sharpenedges.h"

void __cdecl doSharpenEdges(uint8_t* input, uint8_t* output, unsigned int width,
		unsigned int height, unsigned int input_stride, unsigned int output_stride,
		uint8_t* side_buffer, unsigned int side_buffer_stride) {
	buffer_t input_buf = {0}, output_buf = {0}, side_buf = {0};
	
	input_buf.extent[0] = width + 2; input_buf.extent[1] = height + 2;
	input_buf.stride[0] = 1; input_buf.stride[1] = input_stride;
	input_buf.elem_size = 1;
	input_buf.host = input - input_stride - 1;
	
	output_buf.extent[0] = width; output_buf.extent[1] = height;
	output_buf.stride[0] = 1; output_buf.stride[1] = output_stride;
	output_buf.elem_size = 1;
	output_buf.host = output;

	side_buf.extent[0] = width; side_buf.extent[1] = height;
	side_buf.stride[0] = 1; side_buf.stride[1] = side_buffer_stride;
	side_buf.elem_size = 1;
	side_buf.host = side_buffer;

	halide_out_sharpenedges(&side_buf, &input_buf, &output_buf, &side_buf);
}

void __declspec(naked) sharpenEdgesTarget() {
	__asm {
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push ecx
	push edx
	push edi
	push esi

	push [ebp+0x24]
	push [ebp+0x10]
	push [ebp+0x20]
	push [ebp+0x1c]
	push [ebp+0x14]
	push [ebp+0x18]
	push [ebp+0x0c]
	push [ebp+0x08]
	call doSharpenEdges
	add esp, 32

	pop esi
	pop edi
	pop edx
	pop ecx
	pop ebx
	pop eax
	mov esp, ebp
	pop ebp
	ret
	}
}

#include "halide_out_sharpenmore.h"

void __cdecl doSharpenMore(uint8_t* input, uint8_t* output, unsigned int width,
		unsigned int height, unsigned int total_image_width, unsigned int output_stride) {
buffer_t input_buf = {0}, output_buf = {0};
	
	input_buf.extent[0] = width + 2; input_buf.extent[1] = height + 2;
	input_buf.stride[0] = 1; input_buf.stride[1] = total_image_width;
	input_buf.elem_size = 1;
	input_buf.host = input - total_image_width - 1;
	
	output_buf.extent[0] = width; output_buf.extent[1] = height;
	output_buf.stride[0] = 1; output_buf.stride[1] = output_stride;
	output_buf.elem_size = 1;
	output_buf.host = output;

	halide_out_sharpenmore(&input_buf, &output_buf);
}

void __declspec(naked) sharpenMoreTarget() {
	__asm {
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push ecx
	push edx
	push edi
	push esi

	push [ebp+0x1c]
	push [ebp+0x18]
	push [ebp+0x10]
	push [ebp+0x14]
	push [ebp+0x0c]
	push [ebp+0x08]
	call doSharpenMore
	add esp, 24

	pop esi
	pop edi
	pop edx
	pop ecx
	pop ebx
	pop eax
	mov esp, ebp
	pop ebp
	ret
	}
}

#include "halide_out_threshold.h"

void __cdecl doThreshold(uint32_t thresholdInLowByte, uint8_t* inputR, uint8_t* inputG,
		uint8_t* inputB, uint8_t* output, uint32_t height, uint32_t width,
		uint32_t input_stride, uint32_t output_stride) {
	buffer_t input0_buf = {0}, input1_buf = {0}, input2_buf = {0}, output_buf = {0};
	
	input0_buf.extent[0] = width; input0_buf.extent[1] = height;
	input0_buf.stride[0] = 1; input0_buf.stride[1] = input_stride;
	input0_buf.elem_size = 1;
	input0_buf.host = inputG;

	input1_buf.extent[0] = width; input1_buf.extent[1] = height;
	input1_buf.stride[0] = 1; input1_buf.stride[1] = input_stride;
	input1_buf.elem_size = 1;
	input1_buf.host = inputB;

	input2_buf.extent[0] = width; input2_buf.extent[1] = height;
	input2_buf.stride[0] = 1; input2_buf.stride[1] = input_stride;
	input2_buf.elem_size = 1;
	input2_buf.host = inputR;
	
	output_buf.extent[0] = width; output_buf.extent[1] = height;
	output_buf.stride[0] = 1; output_buf.stride[1] = output_stride;
	output_buf.elem_size = 1;
	output_buf.host = output;

	halide_out_threshold(static_cast<uint8_t>(thresholdInLowByte),
		&input0_buf, &input1_buf, &input2_buf, &output_buf);
}

/* threshold calls separate functions to build luminance and do the threshold,
then copies to other planes (?); we replace the first two and jump back for the rest */
unsigned int thresholdJumpback = 0x45ABF0; /* initialized to relative address */
void __declspec(naked) thresholdTarget() {
	__asm {
	push [ebp+0x20]
	call doThreshold
	sub esp, 7*4
	jmp [thresholdJumpback]
	}
}

void patch(char* moduleName, uint32_t relativeAddress, void* patchTarget) {
	uint8_t* baseAddress = (uint8_t*)GetModuleHandle(moduleName);
	if (!baseAddress) return; //module not loaded
	uint8_t* patchAddress = baseAddress + relativeAddress;
	DWORD unused;
	VirtualProtect(patchAddress, 6, PAGE_EXECUTE_READWRITE, &unused);
	int displacement = ((uint8_t*)patchTarget) - patchAddress - 5;
	*patchAddress = 0xE9;
	memcpy(patchAddress+1, &displacement, 4);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		patch(0, 0x1459800, blurTarget);
		patch(0, 0x1465FA0, boxBlurTarget);
		patch("MMXCore.8BX", 0xD6EC, boxBlurTarget);
		patch(0, 0x146EAA0, brightnessTarget);
		patch("MMXCore.8BX", 0x18530, brightnessTarget);
		patch(0, 0x145A460, despeckleTarget);
		patch(0, 0x14EE80, equalizeTarget);
		patch(0, 0x146DB50, invertTarget);
		patch("MMXCore.8BX", 0x2B7A0, invertMMXTarget);
		patch(0, 0x1461B30, noiseTarget);
		patch(0, 0x145A850, sharpenTarget);
		patch(0, 0x1440DE0, sharpenEdgesTarget);
		patch("MMXCore.8BX", 0x1C100, sharpenEdgesTarget);
		patch(0, 0x145A9F0, sharpenMoreTarget);
		//patch(0, 0x1461B30, thresholdTarget);
		patch(0, 0x45ABD5, thresholdTarget);
		thresholdJumpback += (unsigned int)GetModuleHandle(0);

		HANDLE heaps[100];
		GetProcessHeaps(100, heaps);
		hHeap = heaps[2];
	}
	return TRUE;
}
