#include "vector_template.hh"

int main() {
  Vector<float,2> v;
  Vector<float,2> w;
  v[0] = 1;
  v[1] = 2;
  w[0] = 3;
  w[1] = 4;
  cout << v << " + " << w << " = " << v.add(w) << endl;
  cout << v << " - " << w << " = " << v.sub(w) << endl;
  cout << v << " * " << w << " = " << v.mul(w) << endl;
  cout << sqrt(v.mul(v)) << endl;
  Vector<float,4> z = append(v, w);
  cout << v << " ++ " << w << " = " << z << endl;
}
