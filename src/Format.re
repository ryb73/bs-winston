type t;

type namespace;
[@bs.module "winston"] external format: namespace = "";

type combine;
[@bs.get] external combine: namespace => combine = "";
[@bs.send] external applyCombine: combine => combine => array(t) => t = "apply";
let combine = (formats) => applyCombine(combine(format), combine(format), formats);

[@bs.send] external align: namespace => unit => t = "";
[@bs.send] external colorize: namespace => unit => t = "";
[@bs.send] external json: namespace => unit => t = "";
[@bs.send] external prettyPrint: namespace => unit => t = "";
[@bs.send] external printf: namespace => (Js.Dict.t(string) => string) => t = "";
[@bs.send] external simple: namespace => unit => t = "";
[@bs.send] external timestamp: namespace => unit => t = "";

let wrap = (f, arg) => f(format, arg);
let align = wrap(align);
let colorize = wrap(colorize);
let json = wrap(json);
let prettyPrint = wrap(prettyPrint);
let printf = wrap(printf);
let simple = wrap(simple);
let timestamp = wrap(timestamp);
