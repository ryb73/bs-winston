open Winston;

let logger = createLogger(
    ~level=Silly,
    ~transports=[|
        Transports.console(
            ~format=Format.combine([|
                Format.colorize(),
                Format.align(),
                Format.simple(),
            |]),
            ()
        ),
        Transports.file("out.log"),
    |], ()
);

Winston.log(logger, Info, "hi");
Winston.logO(logger, Error, { "yo": "ok", "message": "my log" });
error(logger, "hi");
errorO(logger, { "yo": "ok", "message": "my log" });
warn(logger, "hi");
warnO(logger, { "yo": "ok", "message": "my log" });
info(logger, "hi");
infoO(logger, { "yo": "ok", "message": "my log" });
verbose(logger, "hi");
verboseO(logger, { "yo": "ok", "message": "my log" });
debug(logger, "hi");
debugO(logger, { "yo": "ok", "message": "my log" });
silly(logger, "hi");
sillyO(logger, {
    "yo": {
        "silly": {
            "silly": {
                "silly": {
                    "silly": "silly."
                }
            }
        }
    },
    "message": "my log",
});
