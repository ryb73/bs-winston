type t = WinstonTypes.transport;
let console: (~level: WinstonTypes.level=?, ~format: Format.t=?, unit) => t;
let file: (~level: WinstonTypes.level=?, ~format: Format.t=?, string) => t;
