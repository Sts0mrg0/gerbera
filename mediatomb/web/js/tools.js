function link(req_type, param)
{
    var url = "/content/interface?req_type="+ req_type +"&sid="+ SID +
               "&slt="+ Math.random();
    if (param)
    {
        for (var key in param)
        {
            url += "&" + key +"="+ param[key];
        }
    }
    return url;
}

function isTypeDb()
{
    return (TYPE == "db");
}

function xmlGetElement(parent, name)
{
    var returnVal = Try.these
    (
        function()
        {
            var ns = null;
            var tmpname = name;
            if (tmpname.substring(0, 3) == "dc:")
            {
                ns = "http://purl.org/dc/elements/1.1/";
                tmpname = tmpname.substring(3);
            }
            else if (tmpname.substring(0, 5) == "upnp:")
            {
                ns = "urn:schemas-upnp-org:metadata-1-0/upnp/";
                tmpname = tmpname.substring(5);
            }
            if (ns)
                return parent.getElementsByTagNameNS(ns, tmpname);
            else
                return parent.getElementsByTagName(tmpname);
        },
        function()
        {
            return parent.getElementsByTagName(name);
        }
    );
    if (!returnVal || !returnVal.length)
        return null;
    else
        return returnVal[0];
}

function xmlGetElementText(parent, name)
{
    var el = xmlGetElement(parent, name);
    return xmlGetText(el);
}
function xmlGetText(el)
{
    if (el == null)
        return null;
    if (el.childNodes.length > 1)
        return el.childNodes[1].nodeValue;
    else
        return el.firstChild.nodeValue;
}


function xmlGetAttribute(parent, name)
{
    var a = parent.attributes;
    if (! a)
        return null;
    for (var i = 0; i < a.length; i++)
    {
        if (a[i].name == name)
            return a[i].value;
    }
    return null;
}

