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
Param<uint32_t> p_5("p_5");
Param<double> p_6("p_6");
Param<double> p_9("p_9");
Func output_1;
Expr output_1_p__0 =  
(((((cast<uint64_t>(cast<uint32_t>(((Halide::floor(((cast<double>(1.000000 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 )) / cast<double>(((1  + p_5  + p_5 ) * (1  + p_5  + p_5 ))))) + cast<double>(p_9) ) - (cast<double>(1.000000 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ))))) * cast<uint64_t>(((((1  + p_5  + p_5 ) * (1  + p_5  + p_5 )) >> cast<uint32_t>(1 )) + cast<uint32_t>(input_1(x_0,x_1) ) + cast<uint32_t>(input_1(x_0+1,x_1) ) + cast<uint32_t>(input_1(x_0+2,x_1) ) + cast<uint32_t>(input_1(x_0,x_1+1) ) + cast<uint32_t>(input_1(x_0+1,x_1+1) ) + cast<uint32_t>(input_1(x_0+2,x_1+1) ) + cast<uint32_t>(input_1(x_0,x_1+2) ) + cast<uint32_t>(input_1(x_0+1,x_1+2) ) + cast<uint32_t>(input_1(x_0+2,x_1+2) )))) >> cast<uint32_t>(32)) 
+
(( - ((cast<uint64_t>(cast<uint32_t>(((Halide::floor(((cast<double>(1.000000 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 )) / cast<double>(((1  + p_5  + p_5 ) * (1  + p_5  + p_5 ))))) + 1 ) - (cast<double>(1.000000 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ) * cast<double>(p_6 ))))) * cast<uint64_t>(((((1  + p_5  + p_5 ) * (1  + p_5  + p_5 )) >> cast<uint32_t>(1 )) + cast<uint32_t>(input_1(x_0,x_1) ) + cast<uint32_t>(input_1(x_0+1,x_1) ) + cast<uint32_t>(input_1(x_0+2,x_1) ) + cast<uint32_t>(input_1(x_0,x_1+1) ) + cast<uint32_t>(input_1(x_0+1,x_1+1) ) + cast<uint32_t>(input_1(x_0+2,x_1+1) ) + cast<uint32_t>(input_1(x_0,x_1+2) ) + cast<uint32_t>(input_1(x_0+1,x_1+2) ) + cast<uint32_t>(input_1(x_0+2,x_1+2) )))) >> cast<uint32_t>(32)) 
+
((((((1  + p_5  + p_5 ) * (1  + p_5  + p_5 )) >> cast<uint32_t>(1 )) + cast<uint32_t>(input_1(x_0,x_1) ) + cast<uint32_t>(input_1(x_0+1,x_1) ) + cast<uint32_t>(input_1(x_0+2,x_1) ) + cast<uint32_t>(input_1(x_0,x_1+1) ) + cast<uint32_t>(input_1(x_0+1,x_1+1) ) + cast<uint32_t>(input_1(x_0+2,x_1+1) ) + cast<uint32_t>(input_1(x_0,x_1+2) ) + cast<uint32_t>(input_1(x_0+1,x_1+2) ) + cast<uint32_t>(input_1(x_0+2,x_1+2) ))))) >> cast<uint32_t>(1))) >> cast<uint32_t>(-1  + 32  - 28 )) & 255);

output_1(x_0,x_1) = cast<uint8_t>( clamp(output_1_p__0,0,255) );

Halide::Var _x_00, _x_11;
output_1.specialize(input_1.height() < 16 || input_1.width() < 4);
output_1
.split(x_0, x_0, _x_00, 16)
.split(x_1, x_1, _x_11, 4)
.reorder(_x_00, x_0, _x_11, x_1)
.reorder_storage(x_0, x_1)
.vectorize(_x_00, 8)
#ifdef HELIUM_PARALLEL
.parallel(x_1)
#endif
.compute_root()
;

vector<Argument> arguments;
arguments.push_back(p_5);;
arguments.push_back(p_6);;
arguments.push_back(p_9);;
arguments.push_back(input_1);;
output_1.compile_to_file("halide_out_boxblur",arguments);
return 0;
}