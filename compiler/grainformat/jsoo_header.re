let is_c_drive = path =>
  try(path.[0] == 'C') {
  | Invalid_argument(_) => false
  };

let is_windows_root = path =>
  try(path.[1] == ':') {
  | Invalid_argument(_) => false
  };

let has_non_c_windows_root = root =>
  if (is_windows_root(root) && !is_c_drive(root)) {
    true;
  } else {
    false;
  };

let needs_c_mount =
  List.exists(has_non_c_windows_root, Js_of_ocaml.Sys_js.mount_point());

if (needs_c_mount) {
  Js_of_ocaml.Sys_js.(
    mount(~path="C:/", ~fs_type=Node, (~prefix: _, ~path: _) => None)
  );
};
