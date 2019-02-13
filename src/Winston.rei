module Types: {
    type logger;
    type transport;
    type format;
    type level = Error | Warn | Info | Verbose | Debug | Silly;
    let levelToString: level => string;
};
module Format: {
    type t = Types.format;
    let combine: array(t) => t;
    let align: unit => t;
    let colorize: unit => t;
    let json: unit => t;
    let prettyPrint: unit => t;
    let printf: (Js.Dict.t(string) => string) => t;
    let simple: unit => t;
    let timestamp: unit => t;
};
module Transports: {
    type t = Types.transport;
    let console: (~level: Types.level=?, unit) => t;
    let file: (~level: Types.level=?, string) => t;
};

type t = Types.logger;

let f: Types.transport => t;

let createLogger:
    (~level: Types.level=?, ~format: Types.format=?, ~defaultMeta: Js.t({.. })=?,
    ~transports: array(Types.transport)=?, unit) => t;
let error: (t, string) => unit;
let errorO: (t, Js.t({.. })) => unit;
let warn: (t, string) => unit;
let warnO: (t, Js.t({.. })) => unit;
let info: (t, string) => unit;
let infoO: (t, Js.t({.. })) => unit;
let verbose: (t, string) => unit;
let verboseO: (t, Js.t({.. })) => unit;
let debug: (t, string) => unit;
let debugO: (t, Js.t({.. })) => unit;
let silly: (t, string) => unit;
let sillyO: (t, Js.t({.. })) => unit;
let log: (t, Types.level, string) => unit;
let logO: (t, Types.level, Js.t({.. })) => unit;
