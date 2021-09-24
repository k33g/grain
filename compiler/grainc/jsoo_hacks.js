//Provides: caml_mount_autoload
//Requires: MlNodeDevice, caml_make_path, jsoo_mount_point
function caml_mount_autoload(name, f) {
  var path = caml_make_path(name);
  var name = path.join("/");
  if (name[name.length - 1] != '/') {
    name += '/'
  }
  jsoo_mount_point.push({ path: name, device: new MlNodeDevice(name) })
  return 0;
}
