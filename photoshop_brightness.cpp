#include <Halide.h>
  #include <vector>
  using namespace std;
  using namespace Halide;
  int main(){ 

Var x_0;
Var x_1;
Var x_2;
Var x_3;
ImageParam input_4(UInt(8),1);
ImageParam input_2(UInt(8),2);
Func output_2;
Expr output_2_p__0 = input_4(input_2(x_0,x_1) );
output_2(x_0,x_1) = output_2_p__0;

Halide::Var _x_00, _x_11;
output_2.specialize(input_2.height() < 64 || input_2.width() < 8);
output_2
//.specialize(input_4.height() == 256);
.split(x_0, x_0, _x_00, 64)
.split(x_1, x_1, _x_11, 8)
.reorder(_x_00, x_0, _x_11, x_1)
.reorder_storage(x_1, x_0)
.vectorize(_x_00, 8)
#ifdef HELIUM_PARALLEL
.parallel(x_1)
#endif
.compute_root()
;

vector<Argument> arguments;
arguments.push_back(input_4);;
arguments.push_back(input_2);;
output_2.compile_to_file("halide_out_brightness",arguments);
return 0;
}