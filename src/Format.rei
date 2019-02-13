type t = WinstonTypes.format;
let combine: array(t) => t;
let align: unit => t;
let colorize: unit => t;
let json: unit => t;
let prettyPrint: unit => t;
let printf: (Js.Dict.t(string) => string) => t;
let simple: unit => t;
let timestamp: unit => t;
