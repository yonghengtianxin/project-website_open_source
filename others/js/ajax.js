url = window.location.href; /* ��ȡ����URL */
var xmlhttp;
	if (window.XMLHttpRequest)
	{
		xmlhttp = new XMLHttpRequest();
	}
	else
	{
		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
	}
	xmlhttp.onreadystatechange=function()
	{
		if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
			document.getElementById("main").innerHTML = xmlhttp.responseText;
		}
		else {
			document.getElementById("main").innerHTML = "<p>�Ҳ���ָ��������</p>"
		}
	}
	xmlhttp.open("GET", "/api/gethtml.exe?" + url.substring(url.lastIndexOf("/") + 1, url.length),true);
//	xmlhttp.open("GET", "/blogs/" + url.substring(url.lastIndexOf("/") + 1, url.length),true);
	xmlhttp.send()