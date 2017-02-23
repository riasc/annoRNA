using ArgParse
using Bio.Align

# parse options on command line when started
function parse_command_line()
    settings = ArgParseSettings(prog="search-and-annotate",
        version="0.0.1",
        add_version = true)
    @add_arg_table settings begin
        "--input", "-i"
        help = "samfile"
        arg_type = String
    end
    return parse_args(settings)
end


function go(args)
    filehandle = open(args["input"])
    for line in eachline(filehandle)
        line = replace(line,"\"","") # replace ugly quotes
        line = replace(line,"\n","")
        row = split(line, "\t")

        println(row)
    end

end

function main()
    parsed_args = parse_command_line()
    go(parsed_args)
end

main()