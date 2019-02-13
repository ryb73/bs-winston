module Types = WinstonTypes;
module Format = Format;
module Transports = Transports;

open Types;

type t = logger;

[@bs.val] external f: Types.transport => t = "";

type options;
[@bs.obj]
external options:
    ~level: string=? => ~format: Types.format=? => ~defaultMeta: Js.t({..})=? =>
    ~transports: array(transport)=? => unit => options = "";

[@bs.module "winston"] external createLogger: options => t = "";
let createLogger = (~level=?, ~format=?, ~defaultMeta=?, ~transports=?, ()) =>
    options(
        ~level=?Belt.Option.map(level, levelToString),
        ~format?, ~defaultMeta?, ~transports?, ()
    )
    |> createLogger;

[@bs.send] external error: t => string => unit = "";
[@bs.send] external errorO: t => Js.t({..}) => unit = "error";
[@bs.send] external warn: t => string => unit = "";
[@bs.send] external warnO: t => Js.t({..}) => unit = "warn";
[@bs.send] external info: t => string => unit = "";
[@bs.send] external infoO: t => Js.t({..}) => unit = "info";
[@bs.send] external verbose: t => string => unit = "";
[@bs.send] external verboseO: t => Js.t({..}) => unit = "verbose";
[@bs.send] external debug: t => string => unit = "";
[@bs.send] external debugO: t => Js.t({..}) => unit = "debug";
[@bs.send] external silly: t => string => unit = "";
[@bs.send] external sillyO: t => Js.t({..}) => unit = "silly";

[@bs.send] external log: t => string => string => unit = "";
[@bs.send] external logO: t => string => Js.t({..}) => unit = "log";
let log = (logger, level, message) => log(logger, levelToString(level), message);
let logO = (logger, level, message) => logO(logger, levelToString(level), message);
