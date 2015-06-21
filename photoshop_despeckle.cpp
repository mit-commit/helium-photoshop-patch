#include <Halide.h>
  #include <vector>
  using namespace std;
  using namespace Halide;
  int main(){ 

Var x_0;
Var x_1;
Var x_2;
Var x_3;
ImageParam input_1(UInt(8),2);
Func output_3;
Expr output_3_p__0 =  (  ( (((((7  + cast<uint32_t>(input_1(x_0,x_1) ) + cast<uint32_t>(input_1(x_0+1,x_1) ) + cast<uint32_t>(input_1(x_0+1,x_1) ) + cast<uint32_t>(input_1(x_0+2,x_1) ) + cast<uint32_t>(input_1(x_0,x_1+1) ) + cast<uint32_t>(input_1(x_0,x_1+1) ) + cast<uint32_t>(input_1(x_0+1,x_1+1) ) + cast<uint32_t>(input_1(x_0+1,x_1+1) ) + cast<uint32_t>(input_1(x_0+2,x_1+1) ) + cast<uint32_t>(input_1(x_0+2,x_1+1) ) + cast<uint32_t>(input_1(x_0,x_1+2) ) + cast<uint32_t>(input_1(x_0+1,x_1+2) ) + cast<uint32_t>(input_1(x_0+1,x_1+2) ) + cast<uint32_t>(input_1(x_0+2,x_1+2) )) -  (( (cast<uint64_t>(613566757 ) * cast<uint64_t>((7  + cast<uint32_t>(input_1(x_0,x_1) ) + cast<uint32_t>(input_1(x_0+1,x_1) ) + cast<uint32_t>(input_1(x_0+1,x_1) ) + cast<uint32_t>(input_1(x_0+2,x_1) ) + cast<uint32_t>(input_1(x_0,x_1+1) ) + cast<uint32_t>(input_1(x_0,x_1+1) ) + cast<uint32_t>(input_1(x_0+1,x_1+1) ) + cast<uint32_t>(input_1(x_0+1,x_1+1) ) + cast<uint32_t>(input_1(x_0+2,x_1+1) ) + cast<uint32_t>(input_1(x_0+2,x_1+1) ) + cast<uint32_t>(input_1(x_0,x_1+2) ) + cast<uint32_t>(input_1(x_0+1,x_1+2) ) + cast<uint32_t>(input_1(x_0+1,x_1+2) ) + cast<uint32_t>(input_1(x_0+2,x_1+2) )))) ) >> ( 32))) >> cast<uint32_t>(1 )) +  (( (cast<uint64_t>(613566757 ) * cast<uint64_t>((7  + cast<uint32_t>(input_1(x_0,x_1) ) + cast<uint32_t>(input_1(x_0+1,x_1) ) + cast<uint32_t>(input_1(x_0+1,x_1) ) + cast<uint32_t>(input_1(x_0+2,x_1) ) + cast<uint32_t>(input_1(x_0,x_1+1) ) + cast<uint32_t>(input_1(x_0,x_1+1) ) + cast<uint32_t>(input_1(x_0+1,x_1+1) ) + cast<uint32_t>(input_1(x_0+1,x_1+1) ) + cast<uint32_t>(input_1(x_0+2,x_1+1) ) + cast<uint32_t>(input_1(x_0+2,x_1+1) ) + cast<uint32_t>(input_1(x_0,x_1+2) ) + cast<uint32_t>(input_1(x_0+1,x_1+2) ) + cast<uint32_t>(input_1(x_0+1,x_1+2) ) + cast<uint32_t>(input_1(x_0+2,x_1+2) )))) ) >> ( 32))) >> cast<uint32_t>(3 )) ) & 255 ) ;
output_3(x_0,x_1) = cast<uint8_t>( clamp(output_3_p__0,0,255) );

//old schedule tuned for blur more
Halide:Var _x_00;
output_3.specialize(input_1.height() < 16);
output_3
.split(x_0, x_0, _x_00, 16)
.reorder(_x_00, x_0, x_1)
.reorder_storage(x_1, x_0)
.vectorize(_x_00, 8)
#ifdef HELIUM_PARALLEL
.parallel(x_1)
#endif
.compute_root();

vector<Argument> arguments;
arguments.push_back(input_1);;
output_3.compile_to_file("halide_out_despeckle",arguments);
return 0;
}