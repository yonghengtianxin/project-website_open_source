function changepage(a) {
	encodeURI(a)
	encodeURI(a)
	var xmlhttp;
	if (window.XMLHttpRequest) {
		xmlhttp = new XMLHttpRequest();
	}
	else {
		xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
	}
	xmlhttp.onreadystatechange = function () {
		if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
			document.getElementById("main").innerHTML = xmlhttp.responseText;
		}
	}
	xmlhttp.open("GET", a, true);
	xmlhttp.send();
}

function gotopage(a) {
	window.history.pushState(a, null, "/blogs/" + a);
	document.title = a;
	changepage("/api/gethtml.exe?"+a)
}

function gotogamepage() {
	window.history.pushState("game", null, "/game");
	document.title = "game"
	changepage("game.exe");
}

function gotobloglist() { 
	window.history.pushState("bloglist", null, "/bloglist");
	document.title = "bloglist"
	changepage("/api/bloglist.exe");
}

function gotoindex(a) {
//	window.history.pushState(a, null,"/blogs/index")
	window.history.pushState(window.location.href.substring(window.location.href.lastIndexOf("/") + 1), "index", "/blogs/index")
	document.title = "index"
	changepage("/api/gethtml.exe?index")
}

window.onpopstate = function (event) {
	
	document.title = event.state
	//alert(event.state)
	if (event.state === "game") {
		history.replaceState(event.state, null, event.state);
		changepage("game.exe");
		return;
	}
	if (event.state === "bloglist") {
		history.replaceState(event.state, null, event.state);
		changepage("/api/bloglist.exe");
		return;
	}
	history.replaceState(event.state, null, "/blogs/" + event.state);
	changepage("/api/gethtml.exe?" + event.state)
	//如果需要重新设置title请在文档中设置
//	window.history.pushState(event.state, null, "/blogs/" + event.state);
}

//$("#layui-layer-max")[0].addEventListener("click", changepage("index"));
//document.getElementById("index").addEventListener("click", changepage("/index.html"));
//document.getElementById("index").addEventListener("click", alert("成功");
//document.getElementById("index").onclick = alert("成功");