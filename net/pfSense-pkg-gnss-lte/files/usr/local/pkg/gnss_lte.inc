<?php

define("YMLFILE", "/usr/local/etc/.yml");

function write_conf($gnss_lte_conf) {
	$gnss_on = $gnss_lte_conf['gnss_lte_gnss_on'];

	if (!file_exists(YMLFILE) && !is_link(YMLFILE) && !touch(YMLFILE)) {
		return false;
	}

	if (!is_writable(YMLFILE)) {
		return false;
	}

	$towrite .= "gnss:\n";

	$towrite .= "  gnss_on: {$gnss_on}\n";

	@file_put_contents(YMLFILE, $towrite);
	unset($towrite);
	@chmod(YMLFILE, 0755);

	return;
}

function sync_package_gnss_lte() {
	global $config;
	
	if (is_array($config['installedpackages']['gnss_lte'])) {
	    $gnss_lte_conf = &$config['installedpackages']['gnss_lte']['config'][0];
	} else {
	    $gnss_lte_conf = array();
	}

	if (empty($gnss_lte_conf['gnss_lte_gnss_on'])) {
		$gnss_lte_conf['gnss_lte_gnss_on'] = 'yes';
	}

	write_conf($gnss_lte_conf);

	$gnss_lte_rcfile = "gnss_lte.sh";
	$gnss_lte_bin = "/bin/sh";
	$gnss_lte_script = "/usr/local/etc/frs_gnss_init.sh";
	$gnss_lte_start_cmd = "{$gnss_lte_bin} {$gnss_lte_script}"; 

	write_rcfile(array(
		"file" => "{$gnss_lte_rcfile}",
		"start" => "{$gnss_lte_start_cmd}",
		"stop" => "/usr/bin/killall -9 frs_gnss_init",
		)
	);

	if (is_service_running('gnss_lte')) {
		stop_service("gnss_lte");
		sleep(3);
	}
 
	/* Only (re)start the service when it is enabled */
	if ($gnss_lte_conf['gnss_on'] == "on") {
		start_service("gnss_lte");
		sleep(3);
	} else {
		if (is_service_running('gnss_lte')) {
			stop_service("gnss_lte");
			sleep(3);
		}
		unlink_if_exists('/usr/local/etc/rc.d/gnss_lte.sh');
	}
}

?>
