#include <Halide.h>
  #include <vector>
  using namespace std;
  using namespace Halide;

  int main(){ 

Var x_0;
Var x_1;
Func inter_1;
Param<uint8_t> p_1;
ImageParam input_1(UInt(8),2);
//input_1.set_stride(0,3);
ImageParam input_67(UInt(8),2);
//input_67.set_stride(0,3);
ImageParam input_68(UInt(8),2);
//input_68.set_stride(0,3);

Expr inter_1_0_1 = (( 0  &  1 ) -  1 );
Expr inter_1_0_0 = select((cast<uint32_t>( (  ( (( 8192  + ( 1  * cast<uint32_t>( input_68(x_0,x_1) ) *  4915 ) + (cast<uint32_t>( input_1(x_0,x_1) ) *  9667 ) + (cast<uint32_t>( input_67(x_0,x_1) ) *  1802 )) >> cast<uint32_t>( 14 )) ) & 255 ) ) < cast<uint32_t>( (  ( ( p_1 ) ) & 255 ) )),((( 0  -  1 ) &  1 ) -  1 ),inter_1_0_1);
inter_1(x_0,x_1) = cast<uint8_t>( inter_1_0_0) ;
//inter_1.output_buffer().set_stride(0,3);

Halide::Var _x_00, _x_11;
inter_1
.split(x_0, x_0, _x_00, 64)
.split(x_1, x_1, _x_11, 4)
.reorder(_x_00, _x_11, x_0, x_1)
.reorder_storage(x_1, x_0)
.vectorize(_x_00, 8)
#ifdef HELIUM_PARALLEL
.parallel(x_1)
#endif
.compute_root()
; 

vector<Argument> args;
args.push_back(p_1);
args.push_back(input_1);
args.push_back(input_67);
args.push_back(input_68);

inter_1.compile_to_file("halide_out_threshold",args);
return 0;
}