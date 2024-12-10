import gleam/float

pub type Object {
  Rectangle(x: Float, y: Float)
  Circle(r: Float)
}

pub fn divide(numerator: Float, denominator: Float) -> Result(Float, String) {
  case denominator == 0.0 {
    True -> Error("nepovedlo se")
    _ -> Ok(numerator /. denominator)
  }
}

pub fn area(object: Object) {
  case object {
     Circle(r) -> 
     case float.power(r,2.0) {
       Ok(vysledek) -> 3.14 *. vysledek
       Error(_) -> 0.0
     }
     Rectangle(x,y) -> x *. y
  }
}

pub fn perimeter(object: Object) {
  case object {
    Circle(r) -> 2.0 *. 3.14 *. r
    Rectangle(x,y) -> 2.0 *. {x +. y}
  }
}
