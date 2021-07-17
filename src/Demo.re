
let n0 = Grafeo.Node("test", "Test", Grafeo.Normal)
let n1 = Grafeo.Node("start", "Starting Node", Grafeo.Mdiamond)
let c0 = Grafeo.SimpleConnection(n1, n0)

Js.log(Grafeo.dot_of_grafeo(n1))
Js.log(Grafeo.dot_of_grafeo(n0))
Js.log(Grafeo.dot_of_grafeo(c0))
