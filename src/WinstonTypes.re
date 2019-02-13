type logger;
type transport;
type format;

type level = Error | Warn | Info | Verbose | Debug | Silly;
let levelToString = fun
    | Error => "error" | Warn => "warn" | Info => "info" | Verbose => "verbose"
    | Debug => "debug" | Silly => "silly";
