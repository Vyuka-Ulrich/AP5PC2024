import gleeunit
import gleeunit/should
import objekty/internal

pub fn main() {
  gleeunit.main()
}

// gleeunit test functions end in `_test`
pub fn area_test() {

  internal.Rectangle(5.0, 4.0)
  |> internal.area()
  |> should.equal(20.0)
}
