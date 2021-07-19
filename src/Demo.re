
let n0 = Grafeo.Node("test", "Test", Grafeo.Normal)
let n1 = Grafeo.Node("start", "Starting Node", Grafeo.Mdiamond)
let c0 = Grafeo.BaseConnection(n1, n0)
let g0 = Grafeo.Digraph("G", [|n0, n1, c0|])

Js.log(Grafeo.dot_of_grafeo(g0))
