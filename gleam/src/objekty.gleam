import gleam/io
import gleam/list
import objekty/internal

pub fn arealt(tuple, value) {
  case tuple {
    #(a,_) -> a <. value
  }
}

pub fn main() {
  let objekty = [
    internal.Circle(5.0),
    internal.Rectangle(5.0, 2.0),
    internal.Circle(4.0),
    internal.Rectangle(5.0, 6.0),
  ]

  let l = [5,6,7]
  
  l
  |> list.append([6])
  |> io.debug

  l |> io.debug

  objekty
  |> list.map(fn(objekt) { internal.area(objekt) })
  |> list.zip(list.map(objekty, fn(objekt) {internal.perimeter(objekt)}))
  |> io.debug
  |> list.filter(fn (tup) {arealt(tup, 31.0)})
  |> io.debug
}
