type logger;
type transport;
type format;
type level = Error | Warn | Info | Verbose | Debug | Silly;
let levelToString: level => string;
