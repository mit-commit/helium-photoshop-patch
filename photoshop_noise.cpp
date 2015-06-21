#include <Halide.h>
  #include <vector>
  using namespace std;
  using namespace Halide;
  int main(){ 

Var x_0;
Var x_1;
Var x_2;
Var x_3;
ImageParam input_39(Int(16),1);
ImageParam input_49(UInt(16),1);
ImageParam input_1(UInt(8),2);
Param<int32_t> p_0("p_0");
Param<int32_t> p_1("p_1");
Func output_1;
Expr output_1_p__1 =  (  ( 
	(cast<int32_t>(input_39(
		(2 * x_0 + 0  + p_0  + p_1  + p_1  
		+ cast<uint32_t>(input_49(x_1) ) 
		+ cast<uint32_t>(input_49(x_1) )))) 
	+ cast<uint32_t>(input_1(x_0,x_1))
) ) & 255 ) ;
Expr output_1_p__0 = select(! ((((cast<int32_t>(input_39((2 * x_0 + 0  + p_0  + p_1  + p_1  + cast<uint32_t>(input_49(x_1) ) + cast<uint32_t>(input_49(x_1) )))) + cast<uint32_t>(input_1(x_0,x_1) )) & -256 ) == 0 )), (  ( ( ~ (cast<int32_t>(input_39((2 * x_0 + 0  + p_0  + p_1  + p_1  + cast<uint32_t>(input_49(x_1) ) + cast<uint32_t>(input_49(x_1) )))) + cast<uint32_t>(input_1(x_0,x_1) )) >> cast<uint32_t>(31 )) ) & 255 ) ,output_1_p__1);
output_1(x_0,x_1) = cast<uint8_t>( clamp(output_1_p__0,0,255) );

Halide::Var _x_00, _x_11;
output_1.specialize(input_1.height() < 64 || input_1.width() < 8);
output_1
.split(x_0, x_0, _x_00, 64)
.split(x_1, x_1, _x_11, 8)
.reorder(_x_00, _x_11, x_0, x_1)
.reorder_storage(x_0, x_1)
.vectorize(_x_00, 8)
#ifdef HELIUM_PARALLEL
.parallel(x_1)
#endif
.compute_root()
;

vector<Argument> arguments;
arguments.push_back(p_0);;
arguments.push_back(p_1);;
arguments.push_back(input_39);;
arguments.push_back(input_49);;
arguments.push_back(input_1);;
output_1.compile_to_file("halide_out_noise",arguments);
return 0;
}