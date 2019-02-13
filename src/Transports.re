open WinstonTypes;

type t = transport;

type namespace;
[@bs.module "winston"] external transports: namespace = "";

type constructor;
let newHack: unit => constructor => Js.t({..}) => t =
    () => [%bs.raw {|(Constructor, arg) => new Constructor(arg)|}];

[@bs.get] external console: namespace => constructor = "Console";
let console = console(transports);
let console = (~level=?, ()) =>
    newHack()(console, {
        "level": Belt.Option.map(level, levelToString),
    });

[@bs.get] external file: namespace => constructor = "File";
let file = file(transports);
let file = (~level=?, filename: string) =>
    newHack()(file, {
        "level": Belt.Option.map(level, levelToString),
        "filename": filename
    });
