#include <Halide.h>
  #include <vector>
  using namespace std;
  using namespace Halide;
  
#ifndef AUTOTUNE_HOOK
#define AUTOTUNE_HOOK(x)
#endif
  
  int main(){ 

Var x_0;
Var x_1;
Var x_2;
Var x_3;
ImageParam inter_1_in(UInt(8),2);
ImageParam input_1(UInt(8),2);
ImageParam input_2(UInt(8),2);
Func inter_1;
//Expr inter_1_p__0 = inter_1_in(x_0,x_1) ;
//inter_1(x_0,x_1) = cast<uint8_t>( clamp(inter_1_p__0,0,255) );

Expr inter_1_r0__0 = ( (  ( ((128  + ((128  + ((cast<uint32_t>(input_1(x_0,x_1) ) - cast<uint32_t>(inter_1_in(x_0,x_1) )) * cast<uint32_t>(input_2(x_0,x_1) )) + ((cast<uint32_t>(input_1(x_0,x_1) ) - cast<uint32_t>(inter_1_in(x_0,x_1) )) >> cast<uint32_t>(31 ))) >> cast<uint32_t>(8 )) + ((cast<uint32_t>(input_1(x_0,x_1) ) - cast<uint32_t>(inter_1_in(x_0,x_1) )) * cast<uint32_t>(input_2(x_0,x_1) )) + ((cast<uint32_t>(input_1(x_0,x_1) ) - cast<uint32_t>(inter_1_in(x_0,x_1) )) >> cast<uint32_t>(31 ))) >> cast<uint32_t>(8 )) ) & 8 )  +  ( inter_1_in(x_0,x_1)  ) );
inter_1(x_0,x_1) = cast<uint8_t>( clamp(inter_1_r0__0,0,255) );

Halide::Var _x_00, _x_11;
inter_1.specialize(inter_1_in.height() < 64 || inter_1_in.width() < 8);
inter_1
.split(x_0, x_0, _x_00, 64)
.split(x_1, x_1, _x_11, 8)
.reorder(_x_00, _x_11, x_0, x_1)
.reorder_storage(x_1, x_0)
.vectorize(_x_00, 8)
#ifdef HELIUM_PARALLEL
.parallel(x_1)
#endif
.compute_root()
;


vector<Argument> arguments;
arguments.push_back(inter_1_in);; //output init
arguments.push_back(input_1);; // input
arguments.push_back(input_2);; //intermediate buffer
inter_1.compile_to_file("halide_out_sharpenedges",arguments);
return 0;
}
