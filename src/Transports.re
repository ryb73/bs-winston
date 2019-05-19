open WinstonTypes;

type t = transport;

type namespace;
[@bs.module "winston"] external transports: namespace = "";

type constructor;
let newHack: unit => constructor => Js.t({..}) => t =
    () => [%bs.raw {|(Constructor, arg) => new Constructor(arg)|}];

[@bs.get] external console: namespace => constructor = "Console";
let console = console(transports);
let console = (~level=?, ~format: option(Format.t)=?, ()) =>
    newHack()(console, {
        "level": Belt.Option.map(level, levelToString) |> Js.Undefined.fromOption,
        "format": Js.Undefined.fromOption(format),
    });

[@bs.get] external file: namespace => constructor = "File";
let file = file(transports);
let file = (~level=?, ~format: option(Format.t)=?, filename: string) =>
    newHack()(file, {
        "level": Belt.Option.map(level, levelToString) |> Js.Undefined.fromOption,
        "format": Js.Undefined.fromOption(format),
        "filename": filename,
    });
