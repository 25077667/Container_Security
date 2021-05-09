$hash = "0e878787878787878787878787878787";
if(md5($_GET['pass']) == $hash) {
    echo $FLAG;
}
