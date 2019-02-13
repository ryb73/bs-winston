open WinstonTypes;

type t = logger;

type options;
[@bs.obj]
external options:
    ~level: string=? => ~format: Format.t=? => ~defaultMeta: Js.t({..})=? =>
    ~transports: array(Transports.t)=? => unit => options = "";

[@bs.module "winston"] external createLogger: options => t = "";
let createLogger = (~level=?, ~format=?, ~defaultMeta=?, ~transports=?, ()) =>
    options(
        ~level=?Belt.Option.map(level, levelToString),
        ~format?, ~defaultMeta?, ~transports?, ()
    )
    |> createLogger;

[@bs.send] external log: t => string => string => unit = "";
[@bs.send] external logO: t => string => Js.t({..}) => unit = "log";
let log = (logger, level, message) => log(logger, levelToString(level), message);
let logO = (logger, level, message) => logO(logger, levelToString(level), message);
