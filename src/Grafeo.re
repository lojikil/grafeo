type formo = 
    | Mdiamond
    | Square
    | Record
    | Normal

type grafeo = 
    | BaseNode(string)
    | Node(string, string, formo)
    | BaseConnection(grafeo, grafeo)
    | Connection(grafeo, grafeo, string)
    | Subgraph(string, array(grafeo))

let string_of_formo = fun
    | Mdiamond => "Mdiamond"
    | Square => "square"
    | Record => "record"
    | Normal => "ellipse"

let dot_of_grafeo = (src:grafeo):string => {
    switch(src) {
        | BaseNode(x) => "\"" ++ x ++ "\""
        | Node(name, label, shape) => "\"" ++ name ++ "[label=\"" ++ label ++ "\", shape=\"" ++ string_of_formo(shape) ++ "\"]"
        | _ => "node"
    }
}
