open! Winston;

let logger = createLogger(
    ~level=Silly,
    ~transports=[|
        Transports.console(),
        Transports.file("out.log"),
    |], ~format=Format.combine([|
        Format.colorize(),
        Format.align(),
        Format.simple(),
    |]), ()
);
log(logger, Info, "hi");
logO(logger, Error, { "yo": "ok" });
error(logger, "hi");
errorO(logger, { "yo": "ok" });
warn(logger, "hi");
warnO(logger, { "yo": "ok" });
info(logger, "hi");
infoO(logger, { "yo": "ok" });
verbose(logger, "hi");
verboseO(logger, { "yo": "ok" });
debug(logger, "hi");
debugO(logger, { "yo": "ok" });
silly(logger, "hi");
sillyO(logger, { "yo": "ok" });
