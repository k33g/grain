let needs_c =
  List.exists(
    root => {
      switch (String.index_opt(root, ':')) {
      | Some(1) =>
        if (root.[0] != 'C') {
          true;
        } else {
          false;
        }
      | _ => false
      }
    },
    Js_of_ocaml.Sys_js.mount_point(),
  );

if (needs_c) {
  Js_of_ocaml.Sys_js.mount(~path="C:/", (~prefix: _, ~path: _) => None);
};

List.iter(print_endline, Js_of_ocaml.Sys_js.mount_point());
