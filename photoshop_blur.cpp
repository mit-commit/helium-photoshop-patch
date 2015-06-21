#include <Halide.h>
#include <vector>
using namespace std;
using namespace Halide;

int main(){ 

Var x_0;
Var x_1;
ImageParam input_1(UInt(8),2);
Func output_2;
 output_2(x_0,x_1)  =  cast<uint8_t>(  ( (( 4  + ( 4  * cast<uint32_t>( input_1(x_0+1,x_1+1) )) + cast<uint32_t>( input_1(x_0+1,x_1) ) + cast<uint32_t>( input_1(x_0,x_1+1) ) + cast<uint32_t>( input_1(x_0+2,x_1+1) ) + cast<uint32_t>( input_1(x_0+1,x_1+2) )) >> cast<uint32_t>( 3 )) ) & 255 ) ;
    
Halide::Var _x_00, _x_11;
output_2.specialize(input_1.height() < 32 || input_1.width() < 8);
output_2
.split(x_0, x_0, _x_00, 32)
.split(x_1, x_1, _x_11, 8)
.reorder(_x_00, x_0, _x_11, x_1)
.reorder_storage(x_0, x_1)
.vectorize(_x_00, 8)
#ifdef HELIUM_PARALLEL
.parallel(x_1)
#endif
.compute_root()
;

 vector<Argument> args;
args.push_back(input_1);
output_2.compile_to_file("halide_out_blur", args);
return 0;
}