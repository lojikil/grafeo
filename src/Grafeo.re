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
    | BaseNode(x) => x
    | Node(name, _, _) => name
    | Subgraph(y, _) => y 
    | _ => ""

let dot_of_grafeo = (src:grafeo):string => {
    switch(src) {
        | BaseNode(x) => "\"" ++ x ++ "\""
        | Node(name, label, shape) => "\"" ++ name ++ "\"[label=\"" ++ label ++ "\", shape=\"" ++ string_of_formo(shape) ++ "\"]"
        | SimpleConnection(startnode, endnode) => "\"" ++ name_of_grafeo(startnode) ++ "\" -> \"" ++ name_of_grafeo(endnode) ++ "\""
        | _ => "node"
    }
}
