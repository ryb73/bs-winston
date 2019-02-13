type t = WinstonTypes.transport;
let console: (~level: WinstonTypes.level=?, unit) => t;
let file: (~level: WinstonTypes.level=?, string) => t;
