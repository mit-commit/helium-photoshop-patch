#include <Halide.h>
  #include <vector>
  using namespace std;
  using namespace Halide;
  int main(){ 

Var x_0;
Var x_1;
Var x_2;
Var x_3;
ImageParam input_3(UInt(8),2);
Func inter_1;
Expr inter_1_p__0 = 0 ;
inter_1(x_0) = cast<uint64_t>( /*clamp(*/inter_1_p__0/*,0, 1 << 25)*/ );
RDom r_0(input_3 );
Expr inter_1_r0__0 = (1  + inter_1(input_3(r_0.x,r_0.y) ));
inter_1(input_3(r_0.x,r_0.y)) = cast<uint64_t>( /*clamp(*/inter_1_r0__0/*,0, 1 << 25)*/ );

//TODO: schedule, maybe remove initial update

vector<Argument> arguments;
arguments.push_back(input_3);;
inter_1.compile_to_file("halide_out_equalize",arguments);
return 0;
}