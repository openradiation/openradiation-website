/* To avoid CSS expressions while still supporting IE 7 and IE 6, use this script */
/* The script tag referencing this file must be placed before the ending body tag. */

/* Use conditional comments in order to target IE 7 and older:
	<!--[if lt IE 8]><!-->
	<script src="ie7/ie7.js"></script>
	<!--<![endif]-->
*/

(function() {
	function addIcon(el, entity) {
		var html = el.innerHTML;
		el.innerHTML = '<span style="font-family: \'icomoon-ariane\'">' + entity + '</span>' + html;
	}
	var icons = {
		'icon-internet': '&#xe61c;',
		'icon-bell-slash': '&#xe61a;',
		'icon-bell': '&#xe61b;',
		'icon-bookmark': '&#xf02f;',
		'icon-bookmark-off': '&#xf097;',
		'icon-url': '&#xe61d;',
		'icon-news': '&#xe602;',
		'icon-folder-open': '&#xe603;',
		'icon-bin': '&#xe605;',
		'icon-folder-add': '&#xe606;',
		'icon-cursor-text-2': '&#xe607;',
		'icon-cursor-text-3': '&#xe608;',
		'icon-cursor-text': '&#xe609;',
		'icon-folder': '&#xe60a;',
		'icon-folder-magic': '&#xe60b;',
		'icon-folder-open-2': '&#xe60c;',
		'icon-folder-remove': '&#xe60d;',
		'icon-zip': '&#xe60e;',
		'icon-comments': '&#xe60f;',
		'icon-user': '&#xe611;',
		'icon-users': '&#xe612;',
		'icon-user-add': '&#xe613;',
		'icon-discussions': '&#xe601;',
		'icon-comment-2': '&#xe614;',
		'icon-home': '&#xe610;',
		'icon-flag': '&#xe615;',
		'icon-light-bulb': '&#xe616;',
		'icon-info': '&#xe604;',
		'icon-warning': '&#xe617;',
		'icon-save': '&#xe600;',
		'icon-sound': '&#xe618;',
		'icon-mute': '&#xe619;',
		'icon-file-document': '&#xf016;',
		'icon-tag': '&#xf02d;',
		'icon-tags': '&#xf02e;',
		'icon-minus-square': '&#xf147;',
		'icon-plus-square': '&#xf196;',
		'icon-file-pdf': '&#xf1c1;',
		'icon-file-word': '&#xf1c2;',
		'icon-file-excel': '&#xf1c3;',
		'icon-file-powerpoint': '&#xf1c4;',
		'icon-file-image': '&#xf1c5;',
		'icon-file-zip': '&#xf1c6;',
		'icon-check': '&#xf00c;',
		'icon-delete': '&#xf00d;',
		'icon-admin': '&#xf013;',
		'icon-trash': '&#xf014;',
		'icon-inbox': '&#xf01c;',
		'icon-pencil': '&#xf040;',
		'icon-chevron-left': '&#xf053;',
		'icon-chevron-right': '&#xf054;',
		'icon-plus-circle': '&#xf055;',
		'icon-minus-circle': '&#xf056;',
		'icon-calendar-big': '&#xf073;',
		'icon-discussion': '&#xf075;',
		'icon-quote-left': '&#xf10d;',
		'icon-quote-right': '&#xf10e;',
		'icon-calendar': '&#xf133;',
		'icon-document': '&#xf15b;',
		'0': 0
		},
		els = document.getElementsByTagName('*'),
		i, c, el;
	for (i = 0; ; i += 1) {
		el = els[i];
		if(!el) {
			break;
		}
		c = el.className;
		c = c.match(/icon-[^\s'"]+/);
		if (c && icons[c[0]]) {
			addIcon(el, icons[c[0]]);
		}
	}
}());
