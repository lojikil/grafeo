type formo = 
    | Mdiamond
    | Square
    | Record
    | Normal

type grafeo = 
    | BaseNode(string)
    | Node(string, string, formo)
    | BaseConnection(grafeo, grafeo)
    | SimpleConnection(grafeo, grafeo)
    | Connection(grafeo, grafeo, string)
    | Subgraph(string, array(grafeo))

let string_of_formo = fun
    | Mdiamond => "Mdiamond"
    | Square => "square"
    | Record => "record"
    | Normal => "ellipse"

let name_of_grafeo = fun
    | BaseNode(name) => name
    | Node(name, _, _) => name
    | Subgraph(name, _) => name
    | _ => ""

/* NOTE: normally here I would use Belt.Array.map -> Belt.Array.reduce, but
 * I wanted to make a library that could be used for both native and JS code.
 * if there is something there I can use, please let me know
 * maybe `Array.map -> Array.fold_right` is enough?
 *
 * ~~~
 *
 * NOTO: normale cxi tie mi uzas `Belt.Array.map -> Belt.Array.reduce`, sed
 * mi volas fari programbiblioteko ke povus esti uzata por ambaux indigena
 * kaj JS-a kodo. se estas io kion mi povus uzi, bonvolu informi min
 * eble `Array.map -> Array.fold_right` estas suficxas?
*/

let flatten_nodes = (src: array(grafeo), f:(grafeo => string)) : string => {
    Array.map(f, src) -> Array.fold_left((x, y) => (x ++ "\n" ++ y), "", _)
}

let rec dot_of_grafeo = (src:grafeo):string => {
    switch(src) {
        | BaseNode(x) => "\"" ++ x ++ "\""
        | Node(name, label, shape) => "\"" ++ name ++ "\"[label=\"" ++ label ++ "\", shape=\"" ++ string_of_formo(shape) ++ "\"]"
        | SimpleConnection(startnode, endnode) => "\"" ++ name_of_grafeo(startnode) ++ "\" -> \"" ++ name_of_grafeo(endnode) ++ "\""
        | Connection(startnode, endnode, label) => "\"" ++ name_of_grafeo(startnode) ++ "\" -> \"" ++ name_of_grafeo(endnode) ++ "\"[label=\"" ++ label ++ "\"]"
        | Subgraph(name, nodes) => "subgraph " ++ name ++ " {\n" ++  flatten_nodes(nodes, dot_of_grafeo)  ++ "\n}"
        | _ => "node"
    }
}
