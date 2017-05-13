let module Request = {

  let module RequestAPI = {
    type t 'TRequest 'TOptions 'TUriUrlOptions;

    external defaults0 : t 'TRequest 'TOptions 'TUriUrlOptions => TOptions.t => RequestAPI.t (TRequest.t, TOptions.t, RequiredUriUrl.t) = "" [@@bs.send];
    external defaults1 : t 'TRequest 'TOptions 'TUriUrlOptions => 'a => DefaultUriUrlRequestApi.t (TRequest.t, TOptions.t, OptionalUriUrl.t) = "" [@@bs.send];
    external invoke0 : t 'TRequest 'TOptions 'TUriUrlOptions => string => TOptions.t? => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external invoke1 : t 'TRequest 'TOptions 'TUriUrlOptions => string => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external invoke2 : t 'TRequest 'TOptions 'TUriUrlOptions => 'a => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external get0 : t 'TRequest 'TOptions 'TUriUrlOptions => string => TOptions.t? => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external get1 : t 'TRequest 'TOptions 'TUriUrlOptions => string => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external get2 : t 'TRequest 'TOptions 'TUriUrlOptions => 'a => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external post0 : t 'TRequest 'TOptions 'TUriUrlOptions => string => TOptions.t? => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external post1 : t 'TRequest 'TOptions 'TUriUrlOptions => string => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external post2 : t 'TRequest 'TOptions 'TUriUrlOptions => 'a => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external put0 : t 'TRequest 'TOptions 'TUriUrlOptions => string => TOptions.t? => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external put1 : t 'TRequest 'TOptions 'TUriUrlOptions => string => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external put2 : t 'TRequest 'TOptions 'TUriUrlOptions => 'a => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external head0 : t 'TRequest 'TOptions 'TUriUrlOptions => string => TOptions.t? => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external head1 : t 'TRequest 'TOptions 'TUriUrlOptions => string => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external head2 : t 'TRequest 'TOptions 'TUriUrlOptions => 'a => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external patch0 : t 'TRequest 'TOptions 'TUriUrlOptions => string => TOptions.t? => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external patch1 : t 'TRequest 'TOptions 'TUriUrlOptions => string => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external patch2 : t 'TRequest 'TOptions 'TUriUrlOptions => 'a => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external del0 : t 'TRequest 'TOptions 'TUriUrlOptions => string => TOptions.t? => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external del1 : t 'TRequest 'TOptions 'TUriUrlOptions => string => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external del2 : t 'TRequest 'TOptions 'TUriUrlOptions => 'a => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external delete0 : t 'TRequest 'TOptions 'TUriUrlOptions => string => TOptions.t? => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external delete1 : t 'TRequest 'TOptions 'TUriUrlOptions => string => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external delete2 : t 'TRequest 'TOptions 'TUriUrlOptions => 'a => RequestCallback.t? => unit => TRequest.t = "" [@@bs.send];
    external forever : t 'TRequest 'TOptions 'TUriUrlOptions => 'a => 'a => TRequest.t = "" [@@bs.send];
    external jar : t 'TRequest 'TOptions 'TUriUrlOptions => 'a? => unit => CookieJar.t = "" [@@bs.send];
    external cookie : t 'TRequest 'TOptions 'TUriUrlOptions => string => Cookie.t = "" [@@bs.send];
    external make : initParams::'a => debug::bool => t = "" [@@bs.obj];
    external setInitParams : t => 'a => unit = "initParams" [@@bs.set];
    external getInitParams : t => 'a = "initParams" [@@bs.get];

    external setDebug : t => bool => unit = "debug" [@@bs.set];
    external getDebug : t => bool = "debug" [@@bs.get];

  };

  let module DefaultUriUrlRequestApi = {
    type t 'TRequest 'TOptions 'TUriUrlOptions;

    external defaults : t 'TRequest 'TOptions 'TUriUrlOptions => TOptions.t => DefaultUriUrlRequestApi.t (TRequest.t, TOptions.t, OptionalUriUrl.t) = "" [@@bs.send];
    external invoke : t 'TRequest 'TOptions 'TUriUrlOptions => TRequest.t = "" [@@bs.send];
    external get : t 'TRequest 'TOptions 'TUriUrlOptions => TRequest.t = "" [@@bs.send];
    external post : t 'TRequest 'TOptions 'TUriUrlOptions => TRequest.t = "" [@@bs.send];
    external put : t 'TRequest 'TOptions 'TUriUrlOptions => TRequest.t = "" [@@bs.send];
    external head : t 'TRequest 'TOptions 'TUriUrlOptions => TRequest.t = "" [@@bs.send];
    external patch : t 'TRequest 'TOptions 'TUriUrlOptions => TRequest.t = "" [@@bs.send];
    external del : t 'TRequest 'TOptions 'TUriUrlOptions => TRequest.t = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module CoreOptions = {
    type t;

    external make : baseUrl::string? => callback::('a => RequestResponse.t => 'a => unit)? => jar::'a? => formData::'a? => form::'a? => auth::AuthOptions.t? => oauth::OAuthOptions.t? => aws::AWSOptions.t? => hawk::HawkOptions.t? => qs::'a? => qsStringifyOptions::'a? => qsParseOptions::'a? => json::'a? => jsonReviver::(string => 'a => 'a)? => jsonReplacer::(string => 'a => 'a)? => multipart::'a? => agent::'a? => agentOptions::'a? => agentClass::'a? => forever::'a? => host::string? => port::float? => method::string? => headers::Headers.t? => body::'a? => followRedirect::'a? => followAllRedirects::bool? => maxRedirects::float? => encoding::'a? => pool::'a? => timeout::float? => proxy::'a? => strictSSL::bool? => gzip::bool? => preambleCRLF::bool? => postambleCRLF::bool? => key::Buffer.t? => cert::Buffer.t? => passphrase::string? => ca::'a? => har::HttpArchiveRequest.t? => useQuerystring::bool? => unit => t = "" [@@bs.obj];
    external setBaseUrl : t => option string => unit = "baseUrl" [@@bs.set];
    external getBaseUrl : t => option string = "baseUrl" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setCallback : t => option ('a => RequestResponse.t => 'a => unit) => unit = "callback" [@@bs.set];
    external getCallback : t => option ('a => RequestResponse.t => 'a => unit) = "callback" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setJar : t => option 'a => unit = "jar" [@@bs.set];
    external getJar : t => option 'a = "jar" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setFormData : t => option 'a => unit = "formData" [@@bs.set];
    external getFormData : t => option 'a = "formData" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setForm : t => option 'a => unit = "form" [@@bs.set];
    external getForm : t => option 'a = "form" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAuth : t => option AuthOptions.t => unit = "auth" [@@bs.set];
    external getAuth : t => option AuthOptions.t = "auth" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setOauth : t => option OAuthOptions.t => unit = "oauth" [@@bs.set];
    external getOauth : t => option OAuthOptions.t = "oauth" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAws : t => option AWSOptions.t => unit = "aws" [@@bs.set];
    external getAws : t => option AWSOptions.t = "aws" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHawk : t => option HawkOptions.t => unit = "hawk" [@@bs.set];
    external getHawk : t => option HawkOptions.t = "hawk" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setQs : t => option 'a => unit = "qs" [@@bs.set];
    external getQs : t => option 'a = "qs" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setQsStringifyOptions : t => option 'a => unit = "qsStringifyOptions" [@@bs.set];
    external getQsStringifyOptions : t => option 'a = "qsStringifyOptions" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setQsParseOptions : t => option 'a => unit = "qsParseOptions" [@@bs.set];
    external getQsParseOptions : t => option 'a = "qsParseOptions" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setJson : t => option 'a => unit = "json" [@@bs.set];
    external getJson : t => option 'a = "json" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setJsonReviver : t => option (string => 'a => 'a) => unit = "jsonReviver" [@@bs.set];
    external getJsonReviver : t => option (string => 'a => 'a) = "jsonReviver" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setJsonReplacer : t => option (string => 'a => 'a) => unit = "jsonReplacer" [@@bs.set];
    external getJsonReplacer : t => option (string => 'a => 'a) = "jsonReplacer" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMultipart : t => option 'a => unit = "multipart" [@@bs.set];
    external getMultipart : t => option 'a = "multipart" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAgent : t => option 'a => unit = "agent" [@@bs.set];
    external getAgent : t => option 'a = "agent" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAgentOptions : t => option 'a => unit = "agentOptions" [@@bs.set];
    external getAgentOptions : t => option 'a = "agentOptions" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAgentClass : t => option 'a => unit = "agentClass" [@@bs.set];
    external getAgentClass : t => option 'a = "agentClass" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setForever : t => option 'a => unit = "forever" [@@bs.set];
    external getForever : t => option 'a = "forever" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHost : t => option string => unit = "host" [@@bs.set];
    external getHost : t => option string = "host" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPort : t => option float => unit = "port" [@@bs.set];
    external getPort : t => option float = "port" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMethod : t => option string => unit = "method" [@@bs.set];
    external getMethod : t => option string = "method" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHeaders : t => option Headers.t => unit = "headers" [@@bs.set];
    external getHeaders : t => option Headers.t = "headers" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setBody : t => option 'a => unit = "body" [@@bs.set];
    external getBody : t => option 'a = "body" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setFollowRedirect : t => option 'a => unit = "followRedirect" [@@bs.set];
    external getFollowRedirect : t => option 'a = "followRedirect" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setFollowAllRedirects : t => option bool => unit = "followAllRedirects" [@@bs.set];
    external getFollowAllRedirects : t => option bool = "followAllRedirects" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMaxRedirects : t => option float => unit = "maxRedirects" [@@bs.set];
    external getMaxRedirects : t => option float = "maxRedirects" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setEncoding : t => option 'a => unit = "encoding" [@@bs.set];
    external getEncoding : t => option 'a = "encoding" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPool : t => option 'a => unit = "pool" [@@bs.set];
    external getPool : t => option 'a = "pool" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setTimeout : t => option float => unit = "timeout" [@@bs.set];
    external getTimeout : t => option float = "timeout" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setProxy : t => option 'a => unit = "proxy" [@@bs.set];
    external getProxy : t => option 'a = "proxy" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setStrictSSL : t => option bool => unit = "strictSSL" [@@bs.set];
    external getStrictSSL : t => option bool = "strictSSL" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setGzip : t => option bool => unit = "gzip" [@@bs.set];
    external getGzip : t => option bool = "gzip" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPreambleCRLF : t => option bool => unit = "preambleCRLF" [@@bs.set];
    external getPreambleCRLF : t => option bool = "preambleCRLF" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPostambleCRLF : t => option bool => unit = "postambleCRLF" [@@bs.set];
    external getPostambleCRLF : t => option bool = "postambleCRLF" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setKey : t => option Buffer.t => unit = "key" [@@bs.set];
    external getKey : t => option Buffer.t = "key" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setCert : t => option Buffer.t => unit = "cert" [@@bs.set];
    external getCert : t => option Buffer.t = "cert" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPassphrase : t => option string => unit = "passphrase" [@@bs.set];
    external getPassphrase : t => option string = "passphrase" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setCa : t => option 'a => unit = "ca" [@@bs.set];
    external getCa : t => option 'a = "ca" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHar : t => option HttpArchiveRequest.t => unit = "har" [@@bs.set];
    external getHar : t => option HttpArchiveRequest.t = "har" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setUseQuerystring : t => option bool => unit = "useQuerystring" [@@bs.set];
    external getUseQuerystring : t => option bool = "useQuerystring" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module UriOptions = {
    type t;

    external make : uri::'a => t = "" [@@bs.obj];
    external setUri : t => 'a => unit = "uri" [@@bs.set];
    external getUri : t => 'a = "uri" [@@bs.get];

  };

  let module UrlOptions = {
    type t;

    external make : url::'a => t = "" [@@bs.obj];
    external setUrl : t => 'a => unit = "url" [@@bs.set];
    external getUrl : t => 'a = "url" [@@bs.get];

  };

  let module RequiredUriUrl = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module OptionalUriUrl = {
    type t;

    external make : uri::string? => url::string? => unit => t = "" [@@bs.obj];
    external setUri : t => option string => unit = "uri" [@@bs.set];
    external getUri : t => option string = "uri" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setUrl : t => option string => unit = "url" [@@bs.set];
    external getUrl : t => option string = "url" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module OptionsWithUri = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module OptionsWithUrl = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module Options = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module RequestCallback = {
    type t;

    external invoke : t => 'a => RequestResponse.t => 'a => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module RequestResponse = {
    type t;

    external make : request::Options.t => body::'a => t = "" [@@bs.obj];
    external setRequest : t => Options.t => unit = "request" [@@bs.set];
    external getRequest : t => Options.t = "request" [@@bs.get];

    external setBody : t => 'a => unit = "body" [@@bs.set];
    external getBody : t => 'a = "body" [@@bs.get];

  };

  let module HttpArchiveRequest = {
    type t;

    external make : url::string? => method::string? => headers::(array NameValuePair.t)? => postData::'a? => unit => t = "" [@@bs.obj];
    external setUrl : t => option string => unit = "url" [@@bs.set];
    external getUrl : t => option string = "url" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMethod : t => option string => unit = "method" [@@bs.set];
    external getMethod : t => option string = "method" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHeaders : t => option (array NameValuePair.t) => unit = "headers" [@@bs.set];
    external getHeaders : t => option (array NameValuePair.t) = "headers" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPostData : t => option 'a => unit = "postData" [@@bs.set];
    external getPostData : t => option 'a = "postData" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module NameValuePair = {
    type t;

    external make : name::string => value::string => t = "" [@@bs.obj];
    external setName : t => string => unit = "name" [@@bs.set];
    external getName : t => string = "name" [@@bs.get];

    external setValue : t => string => unit = "value" [@@bs.set];
    external getValue : t => string = "value" [@@bs.get];

  };

  let module Multipart = {
    type t;

    external make : chunked::bool? => data::(array 'a)? => unit => t = "" [@@bs.obj];
    external setChunked : t => option bool => unit = "chunked" [@@bs.set];
    external getChunked : t => option bool = "chunked" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setData : t => option (array 'a) => unit = "data" [@@bs.set];
    external getData : t => option (array 'a) = "data" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module RequestPart = {
    type t;

    external make : headers::Headers.t? => body::'a => unit => t = "" [@@bs.obj];
    external setHeaders : t => option Headers.t => unit = "headers" [@@bs.set];
    external getHeaders : t => option Headers.t = "headers" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setBody : t => 'a => unit = "body" [@@bs.set];
    external getBody : t => 'a = "body" [@@bs.get];

  };

  let module Request = {
    type t;

    external getAgent : t => http.Agent.t = "" [@@bs.send];
    external pipeDest : t => 'a => unit = "" [@@bs.send];
    external setHeader : t => string => string => bool? => unit => Request.t = "" [@@bs.send];
    external setHeaders : t => Headers.t => Request.t = "" [@@bs.send];
    external qs : t => Object.t => bool? => unit => Request.t = "" [@@bs.send];
    external form0 : t => FormData.t = "" [@@bs.send];
    external form1 : t => 'a => Request.t = "" [@@bs.send];
    external multipart : t => (array RequestPart.t) => Request.t = "" [@@bs.send];
    external json : t => 'a => Request.t = "" [@@bs.send];
    external aws : t => AWSOptions.t => bool? => unit => Request.t = "" [@@bs.send];
    external auth : t => string => string => bool? => string? => unit => Request.t = "" [@@bs.send];
    external oauth : t => OAuthOptions.t => Request.t = "" [@@bs.send];
    external jar : t => CookieJar.t => Request.t = "" [@@bs.send];
    external on0 : t => string => ('x => 'y) => t = "" [@@bs.send];
    external on1 : t => 'a => (http.ClientRequest.t => unit) => t = "" [@@bs.send];
    external on2 : t => 'a => (http.IncomingMessage.t => unit) => t = "" [@@bs.send];
    external on3 : t => 'a => ('a => unit) => t = "" [@@bs.send];
    external on4 : t => 'a => (Error.t => unit) => t = "" [@@bs.send];
    external on5 : t => 'a => (http.IncomingMessage.t => 'a => unit) => t = "" [@@bs.send];
    external write0 : t => Buffer.t => ('x => 'y)? => unit => bool = "" [@@bs.send];
    external write1 : t => string => ('x => 'y)? => unit => bool = "" [@@bs.send];
    external write2 : t => string => string => ('x => 'y)? => unit => bool = "" [@@bs.send];
    external write3 : t => string => string? => string? => unit => bool = "" [@@bs.send];
    external end0 : t => unit = "" [@@bs.send];
    external end1 : t => Buffer.t => ('x => 'y)? => unit => unit = "" [@@bs.send];
    external end2 : t => string => ('x => 'y)? => unit => unit = "" [@@bs.send];
    external end3 : t => string => string => ('x => 'y)? => unit => unit = "" [@@bs.send];
    external pause : t => unit = "" [@@bs.send];
    external resume : t => unit = "" [@@bs.send];
    external abort : t => unit = "" [@@bs.send];
    external destroy : t => unit = "" [@@bs.send];
    external toJSON : t => Object.t = "" [@@bs.send];
    external make : readable::bool => writable::bool => t = "" [@@bs.obj];
    external setReadable : t => bool => unit = "readable" [@@bs.set];
    external getReadable : t => bool = "readable" [@@bs.get];

    external setWritable : t => bool => unit = "writable" [@@bs.set];
    external getWritable : t => bool = "writable" [@@bs.get];

  };

  let module Headers = {
    type t;

    external make : value::'a => t = "" [@@bs.obj];
    external setValue : t => 'a => unit = "value" [@@bs.set];
    external getValue : t => 'a = "value" [@@bs.get];

  };

  let module AuthOptions = {
    type t;

    external make : user::string? => username::string? => pass::string? => password::string? => sendImmediately::bool? => bearer::'a? => unit => t = "" [@@bs.obj];
    external setUser : t => option string => unit = "user" [@@bs.set];
    external getUser : t => option string = "user" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setUsername : t => option string => unit = "username" [@@bs.set];
    external getUsername : t => option string = "username" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPass : t => option string => unit = "pass" [@@bs.set];
    external getPass : t => option string = "pass" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPassword : t => option string => unit = "password" [@@bs.set];
    external getPassword : t => option string = "password" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSendImmediately : t => option bool => unit = "sendImmediately" [@@bs.set];
    external getSendImmediately : t => option bool = "sendImmediately" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setBearer : t => option 'a => unit = "bearer" [@@bs.set];
    external getBearer : t => option 'a = "bearer" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module OAuthOptions = {
    type t;

    external make : callback::string? => consumer_key::string? => consumer_secret::string? => token::string? => token_secret::string? => transport_method::'a? => verifier::string? => unit => t = "" [@@bs.obj];
    external setCallback : t => option string => unit = "callback" [@@bs.set];
    external getCallback : t => option string = "callback" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setConsumer_key : t => option string => unit = "consumer_key" [@@bs.set];
    external getConsumer_key : t => option string = "consumer_key" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setConsumer_secret : t => option string => unit = "consumer_secret" [@@bs.set];
    external getConsumer_secret : t => option string = "consumer_secret" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setToken : t => option string => unit = "token" [@@bs.set];
    external getToken : t => option string = "token" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setToken_secret : t => option string => unit = "token_secret" [@@bs.set];
    external getToken_secret : t => option string = "token_secret" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setTransport_method : t => option 'a => unit = "transport_method" [@@bs.set];
    external getTransport_method : t => option 'a = "transport_method" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setVerifier : t => option string => unit = "verifier" [@@bs.set];
    external getVerifier : t => option string = "verifier" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module HawkOptions = {
    type t;

    external make : credentials::'a => t = "" [@@bs.obj];
    external setCredentials : t => 'a => unit = "credentials" [@@bs.set];
    external getCredentials : t => 'a = "credentials" [@@bs.get];

  };

  let module AWSOptions = {
    type t;

    external make : secret::string => bucket::string? => unit => t = "" [@@bs.obj];
    external setSecret : t => string => unit = "secret" [@@bs.set];
    external getSecret : t => string = "secret" [@@bs.get];

    external setBucket : t => option string => unit = "bucket" [@@bs.set];
    external getBucket : t => option string = "bucket" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module CookieJar = {
    type t;

    external setCookie : t => Cookie.t => 'a => 'a? => unit => unit = "" [@@bs.send];
    external getCookieString : t => 'a => string = "" [@@bs.send];
    external getCookies : t => 'a => (array Cookie.t) = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module CookieValue = {
    type t;

    external make : name::string => value::'a => httpOnly::bool => t = "" [@@bs.obj];
    external setName : t => string => unit = "name" [@@bs.set];
    external getName : t => string = "name" [@@bs.get];

    external setValue : t => 'a => unit = "value" [@@bs.set];
    external getValue : t => 'a = "value" [@@bs.get];

    external setHttpOnly : t => bool => unit = "httpOnly" [@@bs.set];
    external getHttpOnly : t => bool = "httpOnly" [@@bs.get];

  };

  let module Cookie = {
    type t;

    external constructor : t => string => Request.t => unit = "" [@@bs.send];
    external toString : t => string = "" [@@bs.send];
    external make : str::string => expires::Date.t => path::string => t = "" [@@bs.obj];
    external setStr : t => string => unit = "str" [@@bs.set];
    external getStr : t => string = "str" [@@bs.get];

    external setExpires : t => Date.t => unit = "expires" [@@bs.set];
    external getExpires : t => Date.t = "expires" [@@bs.get];

    external setPath : t => string => unit = "path" [@@bs.set];
    external getPath : t => string = "path" [@@bs.get];

  };

};
