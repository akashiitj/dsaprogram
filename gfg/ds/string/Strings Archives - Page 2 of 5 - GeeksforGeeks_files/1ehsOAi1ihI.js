/*!CK:3939701251!*//*1441903508,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["nb5fZ"]); }

__d("PagePluginActionTypes",[],function a(b,c,d,e,f,g){c.__markCompiled&&c.__markCompiled();f.exports={CLICK:"click"};},null,{});
__d('ReactSpeedLogger',['BanzaiScuba','NavigationMetrics','ReactDOM'],function a(b,c,d,e,f,g,h,i,j){if(c.__markCompiled)c.__markCompiled();var k='react_speed';function l(r){return r*1000;}function m(r){var s=r.firstChild;return s&&s.getAttribute?s.getAttribute('data-reactid'):'';}function n(r){var s=r.type;if(typeof s==='string')return s;return s.displayName||s.name||'<unkonwn>';}var o=function(r,s,t){var u=new h(k,null,{addBrowserFields:true,addGeoFields:true,addPredictedGeographyFields:true,addMobileDeviceFields:true});u.addNormal('load_id',r);u.addNormal('page',s.page);u.addNormal('page_type',s.pageType);u.addNormal('path',t);if(s[t]&&s.start)u.addInteger('path_duration',s[t]-s.start);return u;},p=function(r,s,t,u){u.forEach(function(v){var w=o(r,s,t);w.addNormal('component',n(v.component));w.addNormal('component_dom_node_react_id',m(v.rootNode));w.addInteger('duration',l(v.duration));w.post();});},q=function(){if(!j.enableRenderMeasurements)return;j.enableRenderMeasurements();};f.exports.init=function(){q();i.addListener(i.Events.NAVIGATION_DONE,function(r,s){if(!j.getRenderMeasurements)return;var t=j.getRenderMeasurements(),u=t.filter(function(w){return (w.startTime>s.start&&w.startTime<=s.tti);});p(r,s,'tti',u);var v=t.filter(function(w){return (w.startTime>s.start&&w.startTime<=s.e2e);});p(r,s,'e2e',v);});};},null);