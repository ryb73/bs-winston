open! Winston;

let logger = createLogger(~transports=[|
    Transports.console(),
    Transports.file("out.log"),
|], ~format=Format.combine([|
    Format.colorize(),
    Format.align(),
    Format.simple(),
|]), ());
log(logger, Info, "hi");
logO(logger, Error, { "yo": "ok" });
