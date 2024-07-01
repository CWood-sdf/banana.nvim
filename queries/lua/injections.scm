; extends

(
(function_call 
  name: (identifier) @name (#eq? @name "nml")
  arguments: (arguments
        (string
          (string_content) @injection.content
          ) @str
     ) @args
  )
  (#set! injection.language "nml")
)
