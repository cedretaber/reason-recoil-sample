[@bs.val] external document: Js.t({..}) = "document";

let content = document##createElement("div");
let () = document##body##appendChild(content);

ReactDOMRe.render(<App />, content);