#include <Halide.h>
  #include <vector>
  using namespace std;
  using namespace Halide;

  int main(){ 

Var x_0;
Var x_1;
ImageParam input_1(UInt(8),2);
Func output_1;
Func output_2;
Func output_3;

 output_1(x_0,x_1)  =  cast<uint8_t>(clamp(cast<int32_t>(  ( ((((((
 	(cast<int32_t>( input_1(x_0+1,x_1+1) )
 	+ cast<int32_t>( input_1(x_0+1,x_1+1) )
 	+ cast<int32_t>( input_1(x_0+1,x_1+1) ) 
 	+ cast<int32_t>( input_1(x_0+1,x_1+1) ) 
 	+ cast<int32_t>( input_1(x_0+1,x_1+1) ) 
 	+ cast<int32_t>( input_1(x_0+1,x_1+1) ) 
 	+ cast<int32_t>( input_1(x_0+1,x_1+1) ) 
 	+ cast<int32_t>( input_1(x_0+1,x_1+1) ))
	- cast<int32_t>( input_1(x_0+1,x_1+2) )) 
 	- cast<int32_t>( input_1(x_0+1,x_1) )) 
	- cast<int32_t>( input_1(x_0,x_1+1) )) 
 	- cast<int32_t>( input_1(x_0+2,x_1+1) ))
 	+ cast<int32_t>( 2 )) 
 	>> cast<int32_t>( 2 ))))
 	, 0, 255) )  ;

Halide::Var _x_00, _x_11;
output_1.specialize(input_1.height() < 16 || input_1.width() < 8);
output_1
.split(x_0, x_0, _x_00, 16)
.split(x_1, x_1, _x_11, 8)
.reorder(_x_00, x_0, _x_11, x_1)
.reorder_storage(x_1, x_0)
.vectorize(_x_00, 8)
#ifdef HELIUM_PARALLEL
.parallel(x_1)
#endif
.compute_root()
;

vector<Argument> args;
args.push_back(input_1);
output_1.compile_to_file("halide_out_sharpen",args);
return 0;
}