let module Document = {
  type t;

  external createElement : t => (_ [@bs.as "webview"]) => Electron.WebViewElement.t = "" [@@bs.send];
  external make : unit => t = "" [@@bs.obj];
};

let module Window = {
  type t;

  external open_ : t => string => string? => string? => unit => Electron.BrowserWindowProxy.t = "" [@@bs.send];
  external make : unit => t = "" [@@bs.obj];
};

let module File = {
  type t;

  external make : path::string => t = "" [@@bs.obj];
  external setPath : t => string => unit = "path" [@@bs.set];
  external getPath : t => string = "path" [@@bs.get];

};

let module NodeRequireFunction = {
  type t;

  external invoke : t => (_ [@bs.as "electron"]) => Electron.ElectronMainAndRenderer.t = "" [@@bs.send];
  external make : unit => t = "" [@@bs.obj];
};

let module Electron = {

  let module Event = {
    type t;

    external make : preventDefault::('x => 'y) => sender::NodeJS.EventEmitter.t => t = "" [@@bs.obj];
    external setPreventDefault : t => ('x => 'y) => unit = "preventDefault" [@@bs.set];
    external getPreventDefault : t => ('x => 'y) = "preventDefault" [@@bs.get];

    external setSender : t => NodeJS.EventEmitter.t => unit = "sender" [@@bs.set];
    external getSender : t => NodeJS.EventEmitter.t = "sender" [@@bs.get];

  };

  let module Point = {
    type t;

    external make : x::float => y::float => t = "" [@@bs.obj];
    external setX : t => float => unit = "x" [@@bs.set];
    external getX : t => float = "x" [@@bs.get];

    external setY : t => float => unit = "y" [@@bs.set];
    external getY : t => float = "y" [@@bs.get];

  };

  let module Size = {
    type t;

    external make : width::float => height::float => t = "" [@@bs.obj];
    external setWidth : t => float => unit = "width" [@@bs.set];
    external getWidth : t => float = "width" [@@bs.get];

    external setHeight : t => float => unit = "height" [@@bs.set];
    external getHeight : t => float = "height" [@@bs.get];

  };

  let module Rectangle = {
    type t;

    external make : x::float => y::float => width::float => height::float => t = "" [@@bs.obj];
    external setX : t => float => unit = "x" [@@bs.set];
    external getX : t => float = "x" [@@bs.get];

    external setY : t => float => unit = "y" [@@bs.set];
    external getY : t => float = "y" [@@bs.get];

    external setWidth : t => float => unit = "width" [@@bs.set];
    external getWidth : t => float = "width" [@@bs.get];

    external setHeight : t => float => unit = "height" [@@bs.set];
    external getHeight : t => float = "height" [@@bs.get];

  };

  let module Destroyable = {
    type t;

    external destroy : t => unit = "" [@@bs.send];
    external isDestroyed : t => bool = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module VibrancyType = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module App = {
    type t;

    let module OptionsType = {
      type t;

      external make : args::(array string)? => execPath::string? => unit => t = "" [@@bs.obj];
      external setArgs : t => option (array string) => unit = "args" [@@bs.set];
      external getArgs : t => option (array string) = "args" [@@bs.get] [@@bs.return null_undefined_to_opt];

      external setExecPath : t => option string => unit = "execPath" [@@bs.set];
      external getExecPath : t => option string = "execPath" [@@bs.get] [@@bs.return null_undefined_to_opt];

    };

    external onWillfinishlaunching : t => (_ [@bs.as "will-finish-launching"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onReady : t => (_ [@bs.as "ready"]) => (Event.t => Object.t => unit) => t = "on" [@@bs.send];
    external onWindowallclosed : t => (_ [@bs.as "window-all-closed"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onBeforequit : t => (_ [@bs.as "before-quit"]) => (Event.t => unit) => t = "on" [@@bs.send];
    external onWillquit : t => (_ [@bs.as "will-quit"]) => (Event.t => unit) => t = "on" [@@bs.send];
    external onQuit : t => (_ [@bs.as "quit"]) => (Event.t => float => unit) => t = "on" [@@bs.send];
    external onOpenfile : t => (_ [@bs.as "open-file"]) => (Event.t => string => unit) => t = "on" [@@bs.send];
    external onOpenurl : t => (_ [@bs.as "open-url"]) => (Event.t => string => unit) => t = "on" [@@bs.send];
    external onActivate : t => (_ [@bs.as "activate"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onContinueactivity : t => (_ [@bs.as "continue-activity"]) => (Event.t => string => Object.t => unit) => t = "on" [@@bs.send];
    external onBrowserwindowblur : t => (_ [@bs.as "browser-window-blur"]) => (Event.t => BrowserWindow.t => unit) => t = "on" [@@bs.send];
    external onBrowserwindowfocus : t => (_ [@bs.as "browser-window-focus"]) => (Event.t => BrowserWindow.t => unit) => t = "on" [@@bs.send];
    external onBrowserwindowcreated : t => (_ [@bs.as "browser-window-created"]) => (Event.t => BrowserWindow.t => unit) => t = "on" [@@bs.send];
    external onWebcontentscreated : t => (_ [@bs.as "web-contents-created"]) => (Event.t => WebContents.t => unit) => t = "on" [@@bs.send];
    external onCertificateerror : t => (_ [@bs.as "certificate-error"]) => (Event.t => WebContents.t => string => string => Certificate.t => (bool => unit) => unit) => t = "on" [@@bs.send];
    external onSelectclientcertificate : t => (_ [@bs.as "select-client-certificate"]) => (Event.t => WebContents.t => string => (array Certificate.t) => (Certificate.t => unit) => unit) => t = "on" [@@bs.send];
    external onLogin : t => (_ [@bs.as "login"]) => (Event.t => WebContents.t => LoginRequest.t => LoginAuthInfo.t => (string => string => unit) => unit) => t = "on" [@@bs.send];
    external onGpuprocesscrashed : t => (_ [@bs.as "gpu-process-crashed"]) => (Event.t => bool => unit) => t = "on" [@@bs.send];
    external onAccessibilitysupportchanged : t => (_ [@bs.as "accessibility-support-changed"]) => (Event.t => bool => unit) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external quit : t => unit = "" [@@bs.send];
    external exit : t => float? => unit => unit = "" [@@bs.send];
    external relaunch : t => OptionsType.t? => unit => unit = "" [@@bs.send];
    external isReady : t => bool = "" [@@bs.send];
    external focus : t => unit = "" [@@bs.send];
    external hide : t => unit = "" [@@bs.send];
    external show : t => unit = "" [@@bs.send];
    external getAppPath : t => string = "" [@@bs.send];
    external getPath : t => AppPathName.t => string = "" [@@bs.send];
    external setPath : t => AppPathName.t => string => unit = "" [@@bs.send];
    external getVersion : t => string = "" [@@bs.send];
    external getName : t => string = "" [@@bs.send];
    external setName : t => string => unit = "" [@@bs.send];
    external getLocale : t => string = "" [@@bs.send];
    external addRecentDocument : t => string => unit = "" [@@bs.send];
    external clearRecentDocuments : t => unit = "" [@@bs.send];
    external setAsDefaultProtocolClient : t => string => string? => (array string)? => unit => bool = "" [@@bs.send];
    external removeAsDefaultProtocolClient : t => string => string? => (array string)? => unit => bool = "" [@@bs.send];
    external isDefaultProtocolClient : t => string => string? => (array string)? => unit => bool = "" [@@bs.send];
    external setUserTasks : t => (array Task.t) => bool = "" [@@bs.send];
    external getJumpListSettings : t => JumpListSettings.t = "" [@@bs.send];
    external setJumpList : t => (array JumpListCategory.t) => SetJumpListResult.t = "" [@@bs.send];
    external makeSingleInstance : t => ((array string) => string => unit) => bool = "" [@@bs.send];
    external releaseSingleInstance : t => unit = "" [@@bs.send];
    external setUserActivity : t => string => Object.t => string? => unit => unit = "" [@@bs.send];
    external getCurrentActivityType : t => string = "" [@@bs.send];
    external setAppUserModelId : t => string => unit = "" [@@bs.send];
    external importCertificate : t => ImportCertificateOptions.t => (float => unit) => unit = "" [@@bs.send];
    external disableHardwareAcceleration : t => unit = "" [@@bs.send];
    external setBadgeCount : t => float => bool = "" [@@bs.send];
    external getBadgeCount : t => float = "" [@@bs.send];
    external isUnityRunning : t => bool = "" [@@bs.send];
    external isAccessibilitySupportEnabled : t => bool = "" [@@bs.send];
    external getLoginItemSettings : t => LoginItemSettings.t = "" [@@bs.send];
    external setLoginItemSettings : t => LoginItemSettings.t => unit = "" [@@bs.send];
    external setAboutPanelOptions : t => AboutPanelOptions.t => unit = "" [@@bs.send];
    external make : commandLine::CommandLine.t => dock::Dock.t => t = "" [@@bs.obj];
    external setCommandLine : t => CommandLine.t => unit = "commandLine" [@@bs.set];
    external getCommandLine : t => CommandLine.t = "commandLine" [@@bs.get];

    external setDock : t => Dock.t => unit = "dock" [@@bs.set];
    external getDock : t => Dock.t = "dock" [@@bs.get];

  };

  let module AppPathName = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module ImportCertificateOptions = {
    type t;

    external make : certificate::string => password::string => t = "" [@@bs.obj];
    external setCertificate : t => string => unit = "certificate" [@@bs.set];
    external getCertificate : t => string = "certificate" [@@bs.get];

    external setPassword : t => string => unit = "password" [@@bs.set];
    external getPassword : t => string = "password" [@@bs.get];

  };

  let module CommandLine = {
    type t;

    external appendSwitch : t => string => string? => unit => unit = "" [@@bs.send];
    external appendArgument : t => string => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module Dock = {
    type t;

    external bounce : t => 'a? => unit => float = "" [@@bs.send];
    external cancelBounce : t => float => unit = "" [@@bs.send];
    external downloadFinished : t => string => unit = "" [@@bs.send];
    external setBadge : t => string => unit = "" [@@bs.send];
    external getBadge : t => string = "" [@@bs.send];
    external hide : t => unit = "" [@@bs.send];
    external show : t => unit = "" [@@bs.send];
    external isVisible : t => bool = "" [@@bs.send];
    external setMenu : t => Menu.t => unit = "" [@@bs.send];
    external setIcon : t => 'a => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module Task = {
    type t;

    external make : program::string => arguments::string => title::string => description::string? => iconPath::string => iconIndex::float? => unit => t = "" [@@bs.obj];
    external setProgram : t => string => unit = "program" [@@bs.set];
    external getProgram : t => string = "program" [@@bs.get];

    external setArguments : t => string => unit = "arguments" [@@bs.set];
    external getArguments : t => string = "arguments" [@@bs.get];

    external setTitle : t => string => unit = "title" [@@bs.set];
    external getTitle : t => string = "title" [@@bs.get];

    external setDescription : t => option string => unit = "description" [@@bs.set];
    external getDescription : t => option string = "description" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIconPath : t => string => unit = "iconPath" [@@bs.set];
    external getIconPath : t => string = "iconPath" [@@bs.get];

    external setIconIndex : t => option float => unit = "iconIndex" [@@bs.set];
    external getIconIndex : t => option float = "iconIndex" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module SetJumpListResult = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module JumpListSettings = {
    type t;

    external make : minItems::float => removedItems::(array JumpListItem.t) => t = "" [@@bs.obj];
    external setMinItems : t => float => unit = "minItems" [@@bs.set];
    external getMinItems : t => float = "minItems" [@@bs.get];

    external setRemovedItems : t => (array JumpListItem.t) => unit = "removedItems" [@@bs.set];
    external getRemovedItems : t => (array JumpListItem.t) = "removedItems" [@@bs.get];

  };

  let module JumpListCategory = {
    type t;

    external make : type_::'a? => name::string? => items::(array JumpListItem.t)? => unit => t = "" [@@bs.obj];
    external setType : t => option 'a => unit = "type" [@@bs.set];
    external getType : t => option 'a = "type" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setName : t => option string => unit = "name" [@@bs.set];
    external getName : t => option string = "name" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setItems : t => option (array JumpListItem.t) => unit = "items" [@@bs.set];
    external getItems : t => option (array JumpListItem.t) = "items" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module JumpListItem = {
    type t;

    external make : type_::'a => path::string? => program::string? => args::string? => title::string? => description::string? => iconPath::string? => iconIndex::float? => unit => t = "" [@@bs.obj];
    external setType : t => 'a => unit = "type" [@@bs.set];
    external getType : t => 'a = "type" [@@bs.get];

    external setPath : t => option string => unit = "path" [@@bs.set];
    external getPath : t => option string = "path" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setProgram : t => option string => unit = "program" [@@bs.set];
    external getProgram : t => option string = "program" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setArgs : t => option string => unit = "args" [@@bs.set];
    external getArgs : t => option string = "args" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setTitle : t => option string => unit = "title" [@@bs.set];
    external getTitle : t => option string = "title" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDescription : t => option string => unit = "description" [@@bs.set];
    external getDescription : t => option string = "description" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIconPath : t => option string => unit = "iconPath" [@@bs.set];
    external getIconPath : t => option string = "iconPath" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIconIndex : t => option float => unit = "iconIndex" [@@bs.set];
    external getIconIndex : t => option float = "iconIndex" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module LoginItemSettings = {
    type t;

    external make : openAtLogin::bool => openAsHidden::bool => wasOpenedAtLogin::bool? => wasOpenedAsHidden::bool? => restoreState::bool? => unit => t = "" [@@bs.obj];
    external setOpenAtLogin : t => bool => unit = "openAtLogin" [@@bs.set];
    external getOpenAtLogin : t => bool = "openAtLogin" [@@bs.get];

    external setOpenAsHidden : t => bool => unit = "openAsHidden" [@@bs.set];
    external getOpenAsHidden : t => bool = "openAsHidden" [@@bs.get];

    external setWasOpenedAtLogin : t => option bool => unit = "wasOpenedAtLogin" [@@bs.set];
    external getWasOpenedAtLogin : t => option bool = "wasOpenedAtLogin" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWasOpenedAsHidden : t => option bool => unit = "wasOpenedAsHidden" [@@bs.set];
    external getWasOpenedAsHidden : t => option bool = "wasOpenedAsHidden" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setRestoreState : t => option bool => unit = "restoreState" [@@bs.set];
    external getRestoreState : t => option bool = "restoreState" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module AboutPanelOptions = {
    type t;

    external make : applicationName::string? => applicationVersion::string? => copyright::string? => credits::string? => version::string? => unit => t = "" [@@bs.obj];
    external setApplicationName : t => option string => unit = "applicationName" [@@bs.set];
    external getApplicationName : t => option string = "applicationName" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setApplicationVersion : t => option string => unit = "applicationVersion" [@@bs.set];
    external getApplicationVersion : t => option string = "applicationVersion" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setCopyright : t => option string => unit = "copyright" [@@bs.set];
    external getCopyright : t => option string = "copyright" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setCredits : t => option string => unit = "credits" [@@bs.set];
    external getCredits : t => option string = "credits" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setVersion : t => option string => unit = "version" [@@bs.set];
    external getVersion : t => option string = "version" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module AutoUpdater = {
    type t;

    external onError : t => (_ [@bs.as "error"]) => (Error.t => unit) => t = "on" [@@bs.send];
    external onCheckingforupdate : t => (_ [@bs.as "checking-for-update"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onUpdateavailable : t => (_ [@bs.as "update-available"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onUpdatenotavailable : t => (_ [@bs.as "update-not-available"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onUpdatedownloaded : t => (_ [@bs.as "update-downloaded"]) => (Event.t => string => string => Date.t => string => unit) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external setFeedURL : t => string => Headers.t? => unit => unit = "" [@@bs.send];
    external getFeedURL : t => string = "" [@@bs.send];
    external checkForUpdates : t => unit = "" [@@bs.send];
    external quitAndInstall : t => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module BrowserWindow = {
    type t;

    let module OptionsType = {
      type t;

      external make : mode::'a => t = "" [@@bs.obj];
      external setMode : t => 'a => unit = "mode" [@@bs.set];
      external getMode : t => 'a = "mode" [@@bs.get];

    };

    external onPagetitleupdated : t => (_ [@bs.as "page-title-updated"]) => (Event.t => string => unit) => t = "on" [@@bs.send];
    external onClose : t => (_ [@bs.as "close"]) => (Event.t => unit) => t = "on" [@@bs.send];
    external onClosed : t => (_ [@bs.as "closed"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onUnresponsive : t => (_ [@bs.as "unresponsive"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onResponsive : t => (_ [@bs.as "responsive"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onBlur : t => (_ [@bs.as "blur"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onFocus : t => (_ [@bs.as "focus"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onShow : t => (_ [@bs.as "show"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onHide : t => (_ [@bs.as "hide"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onReadytoshow : t => (_ [@bs.as "ready-to-show"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onMaximize : t => (_ [@bs.as "maximize"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onUnmaximize : t => (_ [@bs.as "unmaximize"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onMinimize : t => (_ [@bs.as "minimize"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onRestore : t => (_ [@bs.as "restore"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onResize : t => (_ [@bs.as "resize"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onMove : t => (_ [@bs.as "move"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onEnterfullscreen : t => (_ [@bs.as "enter-full-screen"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onLeavefullscreen : t => (_ [@bs.as "leave-full-screen"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onEnterhtmlfullscreen : t => (_ [@bs.as "enter-html-full-screen"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onLeavehtmlfullscreen : t => (_ [@bs.as "leave-html-full-screen"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onAppcommand : t => (_ [@bs.as "app-command"]) => (Event.t => string => unit) => t = "on" [@@bs.send];
    external onScrolltouchbegin : t => (_ [@bs.as "scroll-touch-begin"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onScrolltouchend : t => (_ [@bs.as "scroll-touch-end"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onScrolltouchedge : t => (_ [@bs.as "scroll-touch-edge"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onSwipe : t => (_ [@bs.as "swipe"]) => (Event.t => SwipeDirection.t => unit) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external make : BrowserWindowOptions.t? => unit => t = "BrowserWindow" [@@bs.new] [@@bs.module "electron"];
    external getAllWindows : t => (array BrowserWindow.t) = "" [@@bs.send];
    external getFocusedWindow : t => BrowserWindow.t = "" [@@bs.send];
    external fromWebContents : t => WebContents.t => BrowserWindow.t = "" [@@bs.send];
    external fromId : t => float => BrowserWindow.t = "" [@@bs.send];
    external addDevToolsExtension : t => string => string = "" [@@bs.send];
    external removeDevToolsExtension : t => string => unit = "" [@@bs.send];
    external getDevToolsExtensions : t => DevToolsExtensions.t = "" [@@bs.send];
    external destroy : t => unit = "" [@@bs.send];
    external close : t => unit = "" [@@bs.send];
    external focus : t => unit = "" [@@bs.send];
    external blur : t => unit = "" [@@bs.send];
    external isFocused : t => bool = "" [@@bs.send];
    external isDestroyed : t => bool = "" [@@bs.send];
    external show : t => unit = "" [@@bs.send];
    external showInactive : t => unit = "" [@@bs.send];
    external hide : t => unit = "" [@@bs.send];
    external isVisible : t => bool = "" [@@bs.send];
    external isModal : t => bool = "" [@@bs.send];
    external maximize : t => unit = "" [@@bs.send];
    external unmaximize : t => unit = "" [@@bs.send];
    external isMaximized : t => bool = "" [@@bs.send];
    external minimize : t => unit = "" [@@bs.send];
    external restore : t => unit = "" [@@bs.send];
    external isMinimized : t => bool = "" [@@bs.send];
    external setFullScreen : t => bool => unit = "" [@@bs.send];
    external isFullScreen : t => bool = "" [@@bs.send];
    external setAspectRatio : t => float => Size.t? => unit => unit = "" [@@bs.send];
    external previewFile : t => string => string? => unit => unit = "" [@@bs.send];
    external setBounds : t => Rectangle.t => bool? => unit => unit = "" [@@bs.send];
    external getBounds : t => Rectangle.t = "" [@@bs.send];
    external setContentBounds : t => Rectangle.t => bool? => unit => unit = "" [@@bs.send];
    external getContentBounds : t => Rectangle.t = "" [@@bs.send];
    external setSize : t => float => float => bool? => unit => unit = "" [@@bs.send];
    external getSize : t => (array float) = "" [@@bs.send];
    external setContentSize : t => float => float => bool? => unit => unit = "" [@@bs.send];
    external getContentSize : t => (array float) = "" [@@bs.send];
    external setMinimumSize : t => float => float => unit = "" [@@bs.send];
    external getMinimumSize : t => (array float) = "" [@@bs.send];
    external setMaximumSize : t => float => float => unit = "" [@@bs.send];
    external getMaximumSize : t => (array float) = "" [@@bs.send];
    external setResizable : t => bool => unit = "" [@@bs.send];
    external isResizable : t => bool = "" [@@bs.send];
    external setMovable : t => bool => unit = "" [@@bs.send];
    external isMovable : t => bool = "" [@@bs.send];
    external setMinimizable : t => bool => unit = "" [@@bs.send];
    external isMinimizable : t => bool = "" [@@bs.send];
    external setMaximizable : t => bool => unit = "" [@@bs.send];
    external isMaximizable : t => bool = "" [@@bs.send];
    external setFullScreenable : t => bool => unit = "" [@@bs.send];
    external isFullScreenable : t => bool = "" [@@bs.send];
    external setClosable : t => bool => unit = "" [@@bs.send];
    external isClosable : t => bool = "" [@@bs.send];
    external setAlwaysOnTop : t => bool => WindowLevel.t? => unit => unit = "" [@@bs.send];
    external isAlwaysOnTop : t => bool = "" [@@bs.send];
    external center : t => unit = "" [@@bs.send];
    external setPosition : t => float => float => bool? => unit => unit = "" [@@bs.send];
    external getPosition : t => (array float) = "" [@@bs.send];
    external setTitle : t => string => unit = "" [@@bs.send];
    external getTitle : t => string = "" [@@bs.send];
    external setSheetOffset : t => float => float? => unit => unit = "" [@@bs.send];
    external flashFrame : t => bool => unit = "" [@@bs.send];
    external setSkipTaskbar : t => bool => unit = "" [@@bs.send];
    external setKiosk : t => bool => unit = "" [@@bs.send];
    external isKiosk : t => bool = "" [@@bs.send];
    external getNativeWindowHandle : t => Buffer.t = "" [@@bs.send];
    external hookWindowMessage : t => float => ('x => 'y) => unit = "" [@@bs.send];
    external isWindowMessageHooked : t => float => bool = "" [@@bs.send];
    external unhookWindowMessage : t => float => unit = "" [@@bs.send];
    external unhookAllWindowMessages : t => unit = "" [@@bs.send];
    external setRepresentedFilename : t => string => unit = "" [@@bs.send];
    external getRepresentedFilename : t => string = "" [@@bs.send];
    external setDocumentEdited : t => bool => unit = "" [@@bs.send];
    external isDocumentEdited : t => bool = "" [@@bs.send];
    external focusOnWebView : t => unit = "" [@@bs.send];
    external blurWebView : t => unit = "" [@@bs.send];
    external capturePage0 : t => Rectangle.t => (NativeImage.t => unit) => unit = "capturePage" [@@bs.send];
    external capturePage1 : t => (NativeImage.t => unit) => unit = "capturePage" [@@bs.send];
    external loadURL : t => string => LoadURLOptions.t? => unit => unit = "" [@@bs.send];
    external reload : t => unit = "" [@@bs.send];
    external setMenu : t => 'a => unit = "" [@@bs.send];
    external setProgressBar : t => float => OptionsType.t? => unit => unit = "" [@@bs.send];
    external setOverlayIcon : t => NativeImage.t => string => unit = "" [@@bs.send];
    external setHasShadow : t => bool => unit = "" [@@bs.send];
    external hasShadow : t => bool = "" [@@bs.send];
    external setThumbarButtons : t => (array ThumbarButton.t) => bool = "" [@@bs.send];
    external setThumbnailClip : t => Rectangle.t => bool = "" [@@bs.send];
    external setThumbnailToolTip : t => string => bool = "" [@@bs.send];
    external showDefinitionForSelection : t => unit = "" [@@bs.send];
    external setIcon : t => NativeImage.t => unit = "" [@@bs.send];
    external setAutoHideMenuBar : t => bool => unit = "" [@@bs.send];
    external isMenuBarAutoHide : t => bool = "" [@@bs.send];
    external setMenuBarVisibility : t => bool => unit = "" [@@bs.send];
    external isMenuBarVisible : t => bool = "" [@@bs.send];
    external setVisibleOnAllWorkspaces : t => bool => unit = "" [@@bs.send];
    external isVisibleOnAllWorkspaces : t => bool = "" [@@bs.send];
    external setIgnoreMouseEvents : t => bool => unit = "" [@@bs.send];
    external setContentProtection : t => bool => unit = "" [@@bs.send];
    external setFocusable : t => bool => unit = "" [@@bs.send];
    external setParentWindow : t => BrowserWindow.t => unit = "" [@@bs.send];
    external getParentWindow : t => BrowserWindow.t = "" [@@bs.send];
    external getChildWindows : t => (array BrowserWindow.t) = "" [@@bs.send];
    external setVibrancy : t => VibrancyType.t => unit = "" [@@bs.send];
    external setWebContents : t => WebContents.t => unit = "webContents" [@@bs.set];
    external getWebContents : t => WebContents.t = "webContents" [@@bs.get];

    external setId : t => float => unit = "id" [@@bs.set];
    external getId : t => float = "id" [@@bs.get];

  };

  let module WindowLevel = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module SwipeDirection = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module ThumbarButtonFlags = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module ThumbarButton = {
    type t;

    external make : icon::'a => click::('x => 'y) => tooltip::string? => flags::(array ThumbarButtonFlags.t)? => unit => t = "" [@@bs.obj];
    external setIcon : t => 'a => unit = "icon" [@@bs.set];
    external getIcon : t => 'a = "icon" [@@bs.get];

    external setClick : t => ('x => 'y) => unit = "click" [@@bs.set];
    external getClick : t => ('x => 'y) = "click" [@@bs.get];

    external setTooltip : t => option string => unit = "tooltip" [@@bs.set];
    external getTooltip : t => option string = "tooltip" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setFlags : t => option (array ThumbarButtonFlags.t) => unit = "flags" [@@bs.set];
    external getFlags : t => option (array ThumbarButtonFlags.t) = "flags" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module DevToolsExtensions = {
    type t;

    let module ValueType = {
      type t;

      external make : name::string => value::string => t = "" [@@bs.obj];
      external setName : t => string => unit = "name" [@@bs.set];
      external getName : t => string = "name" [@@bs.get];

      external setValue : t => string => unit = "value" [@@bs.set];
      external getValue : t => string = "value" [@@bs.get];

    };

    external value : t => string => ValueType.t = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module WebPreferences = {
    type t;

    let module DefaultFontFamilyType = {
      type t;

      external make : standard::string? => serif::string? => sansSerif::string? => monospace::string? => unit => t = "" [@@bs.obj];
      external setStandard : t => option string => unit = "standard" [@@bs.set];
      external getStandard : t => option string = "standard" [@@bs.get] [@@bs.return null_undefined_to_opt];

      external setSerif : t => option string => unit = "serif" [@@bs.set];
      external getSerif : t => option string = "serif" [@@bs.get] [@@bs.return null_undefined_to_opt];

      external setSansSerif : t => option string => unit = "sansSerif" [@@bs.set];
      external getSansSerif : t => option string = "sansSerif" [@@bs.get] [@@bs.return null_undefined_to_opt];

      external setMonospace : t => option string => unit = "monospace" [@@bs.set];
      external getMonospace : t => option string = "monospace" [@@bs.get] [@@bs.return null_undefined_to_opt];

    };

    external make : devTools::bool? => nodeIntegration::bool? => preload::string? => session::Session.t? => partition::string? => zoomFactor::float? => javascript::bool? => webSecurity::bool? => allowDisplayingInsecureContent::bool? => allowRunningInsecureContent::bool? => images::bool? => textAreasAreResizable::bool? => webgl::bool? => webaudio::bool? => plugins::bool? => experimentalFeatures::bool? => experimentalCanvasFeatures::bool? => directWrite::bool? => scrollBounce::bool? => blinkFeatures::string? => disableBlinkFeatures::string? => defaultFontFamily::DefaultFontFamilyType.t? => defaultFontSize::float? => defaultMonospaceFontSize::float? => minimumFontSize::float? => defaultEncoding::string? => backgroundThrottling::bool? => offscreen::bool? => sandbox::bool? => unit => t = "" [@@bs.obj];
    external setDevTools : t => option bool => unit = "devTools" [@@bs.set];
    external getDevTools : t => option bool = "devTools" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setNodeIntegration : t => option bool => unit = "nodeIntegration" [@@bs.set];
    external getNodeIntegration : t => option bool = "nodeIntegration" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPreload : t => option string => unit = "preload" [@@bs.set];
    external getPreload : t => option string = "preload" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSession : t => option Session.t => unit = "session" [@@bs.set];
    external getSession : t => option Session.t = "session" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPartition : t => option string => unit = "partition" [@@bs.set];
    external getPartition : t => option string = "partition" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setZoomFactor : t => option float => unit = "zoomFactor" [@@bs.set];
    external getZoomFactor : t => option float = "zoomFactor" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setJavascript : t => option bool => unit = "javascript" [@@bs.set];
    external getJavascript : t => option bool = "javascript" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWebSecurity : t => option bool => unit = "webSecurity" [@@bs.set];
    external getWebSecurity : t => option bool = "webSecurity" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAllowDisplayingInsecureContent : t => option bool => unit = "allowDisplayingInsecureContent" [@@bs.set];
    external getAllowDisplayingInsecureContent : t => option bool = "allowDisplayingInsecureContent" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAllowRunningInsecureContent : t => option bool => unit = "allowRunningInsecureContent" [@@bs.set];
    external getAllowRunningInsecureContent : t => option bool = "allowRunningInsecureContent" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setImages : t => option bool => unit = "images" [@@bs.set];
    external getImages : t => option bool = "images" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setTextAreasAreResizable : t => option bool => unit = "textAreasAreResizable" [@@bs.set];
    external getTextAreasAreResizable : t => option bool = "textAreasAreResizable" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWebgl : t => option bool => unit = "webgl" [@@bs.set];
    external getWebgl : t => option bool = "webgl" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWebaudio : t => option bool => unit = "webaudio" [@@bs.set];
    external getWebaudio : t => option bool = "webaudio" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPlugins : t => option bool => unit = "plugins" [@@bs.set];
    external getPlugins : t => option bool = "plugins" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setExperimentalFeatures : t => option bool => unit = "experimentalFeatures" [@@bs.set];
    external getExperimentalFeatures : t => option bool = "experimentalFeatures" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setExperimentalCanvasFeatures : t => option bool => unit = "experimentalCanvasFeatures" [@@bs.set];
    external getExperimentalCanvasFeatures : t => option bool = "experimentalCanvasFeatures" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDirectWrite : t => option bool => unit = "directWrite" [@@bs.set];
    external getDirectWrite : t => option bool = "directWrite" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setScrollBounce : t => option bool => unit = "scrollBounce" [@@bs.set];
    external getScrollBounce : t => option bool = "scrollBounce" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setBlinkFeatures : t => option string => unit = "blinkFeatures" [@@bs.set];
    external getBlinkFeatures : t => option string = "blinkFeatures" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDisableBlinkFeatures : t => option string => unit = "disableBlinkFeatures" [@@bs.set];
    external getDisableBlinkFeatures : t => option string = "disableBlinkFeatures" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDefaultFontFamily : t => option DefaultFontFamilyType.t => unit = "defaultFontFamily" [@@bs.set];
    external getDefaultFontFamily : t => option DefaultFontFamilyType.t = "defaultFontFamily" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDefaultFontSize : t => option float => unit = "defaultFontSize" [@@bs.set];
    external getDefaultFontSize : t => option float = "defaultFontSize" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDefaultMonospaceFontSize : t => option float => unit = "defaultMonospaceFontSize" [@@bs.set];
    external getDefaultMonospaceFontSize : t => option float = "defaultMonospaceFontSize" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMinimumFontSize : t => option float => unit = "minimumFontSize" [@@bs.set];
    external getMinimumFontSize : t => option float = "minimumFontSize" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDefaultEncoding : t => option string => unit = "defaultEncoding" [@@bs.set];
    external getDefaultEncoding : t => option string = "defaultEncoding" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setBackgroundThrottling : t => option bool => unit = "backgroundThrottling" [@@bs.set];
    external getBackgroundThrottling : t => option bool = "backgroundThrottling" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setOffscreen : t => option bool => unit = "offscreen" [@@bs.set];
    external getOffscreen : t => option bool = "offscreen" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSandbox : t => option bool => unit = "sandbox" [@@bs.set];
    external getSandbox : t => option bool = "sandbox" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module BrowserWindowOptions = {
    type t;

    external make : width::float? => height::float? => x::float? => y::float? => useContentSize::bool? => center::bool? => minWidth::float? => minHeight::float? => maxWidth::float? => maxHeight::float? => resizable::bool? => movable::bool? => minimizable::bool? => maximizable::bool? => closable::bool? => focusable::bool? => alwaysOnTop::bool? => fullscreen::bool? => fullscreenable::bool? => skipTaskbar::bool? => kiosk::bool? => title::string? => icon::'a? => show::bool? => frame::bool? => parent::BrowserWindow.t? => modal::bool? => acceptFirstMouse::bool? => disableAutoHideCursor::bool? => autoHideMenuBar::bool? => enableLargerThanScreen::bool? => backgroundColor::string? => hasShadow::bool? => darkTheme::bool? => transparent::bool? => type_::BrowserWindowType.t? => titleBarStyle::'a? => thickFrame::bool? => vibrancy::VibrancyType.t? => webPreferences::WebPreferences.t? => unit => t = "" [@@bs.obj];
    external setWidth : t => option float => unit = "width" [@@bs.set];
    external getWidth : t => option float = "width" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHeight : t => option float => unit = "height" [@@bs.set];
    external getHeight : t => option float = "height" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setX : t => option float => unit = "x" [@@bs.set];
    external getX : t => option float = "x" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setY : t => option float => unit = "y" [@@bs.set];
    external getY : t => option float = "y" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setUseContentSize : t => option bool => unit = "useContentSize" [@@bs.set];
    external getUseContentSize : t => option bool = "useContentSize" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setCenter : t => option bool => unit = "center" [@@bs.set];
    external getCenter : t => option bool = "center" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMinWidth : t => option float => unit = "minWidth" [@@bs.set];
    external getMinWidth : t => option float = "minWidth" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMinHeight : t => option float => unit = "minHeight" [@@bs.set];
    external getMinHeight : t => option float = "minHeight" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMaxWidth : t => option float => unit = "maxWidth" [@@bs.set];
    external getMaxWidth : t => option float = "maxWidth" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMaxHeight : t => option float => unit = "maxHeight" [@@bs.set];
    external getMaxHeight : t => option float = "maxHeight" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setResizable : t => option bool => unit = "resizable" [@@bs.set];
    external getResizable : t => option bool = "resizable" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMovable : t => option bool => unit = "movable" [@@bs.set];
    external getMovable : t => option bool = "movable" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMinimizable : t => option bool => unit = "minimizable" [@@bs.set];
    external getMinimizable : t => option bool = "minimizable" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMaximizable : t => option bool => unit = "maximizable" [@@bs.set];
    external getMaximizable : t => option bool = "maximizable" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setClosable : t => option bool => unit = "closable" [@@bs.set];
    external getClosable : t => option bool = "closable" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setFocusable : t => option bool => unit = "focusable" [@@bs.set];
    external getFocusable : t => option bool = "focusable" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAlwaysOnTop : t => option bool => unit = "alwaysOnTop" [@@bs.set];
    external getAlwaysOnTop : t => option bool = "alwaysOnTop" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setFullscreen : t => option bool => unit = "fullscreen" [@@bs.set];
    external getFullscreen : t => option bool = "fullscreen" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setFullscreenable : t => option bool => unit = "fullscreenable" [@@bs.set];
    external getFullscreenable : t => option bool = "fullscreenable" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSkipTaskbar : t => option bool => unit = "skipTaskbar" [@@bs.set];
    external getSkipTaskbar : t => option bool = "skipTaskbar" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setKiosk : t => option bool => unit = "kiosk" [@@bs.set];
    external getKiosk : t => option bool = "kiosk" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setTitle : t => option string => unit = "title" [@@bs.set];
    external getTitle : t => option string = "title" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIcon : t => option 'a => unit = "icon" [@@bs.set];
    external getIcon : t => option 'a = "icon" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setShow : t => option bool => unit = "show" [@@bs.set];
    external getShow : t => option bool = "show" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setFrame : t => option bool => unit = "frame" [@@bs.set];
    external getFrame : t => option bool = "frame" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setParent : t => option BrowserWindow.t => unit = "parent" [@@bs.set];
    external getParent : t => option BrowserWindow.t = "parent" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setModal : t => option bool => unit = "modal" [@@bs.set];
    external getModal : t => option bool = "modal" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAcceptFirstMouse : t => option bool => unit = "acceptFirstMouse" [@@bs.set];
    external getAcceptFirstMouse : t => option bool = "acceptFirstMouse" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDisableAutoHideCursor : t => option bool => unit = "disableAutoHideCursor" [@@bs.set];
    external getDisableAutoHideCursor : t => option bool = "disableAutoHideCursor" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAutoHideMenuBar : t => option bool => unit = "autoHideMenuBar" [@@bs.set];
    external getAutoHideMenuBar : t => option bool = "autoHideMenuBar" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setEnableLargerThanScreen : t => option bool => unit = "enableLargerThanScreen" [@@bs.set];
    external getEnableLargerThanScreen : t => option bool = "enableLargerThanScreen" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setBackgroundColor : t => option string => unit = "backgroundColor" [@@bs.set];
    external getBackgroundColor : t => option string = "backgroundColor" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHasShadow : t => option bool => unit = "hasShadow" [@@bs.set];
    external getHasShadow : t => option bool = "hasShadow" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDarkTheme : t => option bool => unit = "darkTheme" [@@bs.set];
    external getDarkTheme : t => option bool = "darkTheme" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setTransparent : t => option bool => unit = "transparent" [@@bs.set];
    external getTransparent : t => option bool = "transparent" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setType : t => option BrowserWindowType.t => unit = "type" [@@bs.set];
    external getType : t => option BrowserWindowType.t = "type" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setTitleBarStyle : t => option 'a => unit = "titleBarStyle" [@@bs.set];
    external getTitleBarStyle : t => option 'a = "titleBarStyle" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setThickFrame : t => option bool => unit = "thickFrame" [@@bs.set];
    external getThickFrame : t => option bool = "thickFrame" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setVibrancy : t => option VibrancyType.t => unit = "vibrancy" [@@bs.set];
    external getVibrancy : t => option VibrancyType.t = "vibrancy" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWebPreferences : t => option WebPreferences.t => unit = "webPreferences" [@@bs.set];
    external getWebPreferences : t => option WebPreferences.t = "webPreferences" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module BrowserWindowType = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module BrowserWindowTypeLinux = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module BrowserWindowTypeMac = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module BrowserWindowTypeWindows = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module Clipboard = {
    type t;

    external readText : t => ClipboardType.t? => unit => string = "" [@@bs.send];
    external writeText : t => string => ClipboardType.t? => unit => unit = "" [@@bs.send];
    external readHTML : t => ClipboardType.t? => unit => string = "" [@@bs.send];
    external writeHTML : t => string => ClipboardType.t? => unit => unit = "" [@@bs.send];
    external readImage : t => ClipboardType.t? => unit => NativeImage.t = "" [@@bs.send];
    external writeImage : t => NativeImage.t => ClipboardType.t? => unit => unit = "" [@@bs.send];
    external readRTF : t => ClipboardType.t? => unit => string = "" [@@bs.send];
    external writeRTF : t => string => ClipboardType.t? => unit => unit = "" [@@bs.send];
    external clear : t => ClipboardType.t? => unit => unit = "" [@@bs.send];
    external availableFormats : t => ClipboardType.t? => unit => (array string) = "" [@@bs.send];
    external has : t => string => ClipboardType.t? => unit => bool = "" [@@bs.send];
    external read : t => string => ClipboardType.t? => unit => 'a = "" [@@bs.send];
    external write : t => 'a => ClipboardType.t? => unit => unit = "" [@@bs.send];
    external readBookmark : t => Bookmark.t = "" [@@bs.send];
    external writeBookmark : t => string => string => ClipboardType.t? => unit => unit = "" [@@bs.send];
    external readFindText : t => string = "" [@@bs.send];
    external writeFindText : t => string => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module ClipboardType = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module Bookmark = {
    type t;

    external make : title::string => url::string => t = "" [@@bs.obj];
    external setTitle : t => string => unit = "title" [@@bs.set];
    external getTitle : t => string = "title" [@@bs.get];

    external setUrl : t => string => unit = "url" [@@bs.set];
    external getUrl : t => string = "url" [@@bs.get];

  };

  let module ContentTracing = {
    type t;

    external getCategories : t => ((array string) => unit) => unit = "" [@@bs.send];
    external startRecording : t => ContentTracingOptions.t => ('x => 'y) => unit = "" [@@bs.send];
    external stopRecording : t => string => (string => unit) => unit = "" [@@bs.send];
    external startMonitoring : t => ContentTracingOptions.t => ('x => 'y) => unit = "" [@@bs.send];
    external stopMonitoring : t => ('x => 'y) => unit = "" [@@bs.send];
    external captureMonitoringSnapshot : t => string => (string => unit) => unit = "" [@@bs.send];
    external getTraceBufferUsage : t => ('x => 'y) => unit = "" [@@bs.send];
    external setWatchEvent : t => string => string => ('x => 'y) => unit = "" [@@bs.send];
    external cancelWatchEvent : t => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module ContentTracingOptions = {
    type t;

    external make : categoryFilter::string => traceOptions::string => t = "" [@@bs.obj];
    external setCategoryFilter : t => string => unit = "categoryFilter" [@@bs.set];
    external getCategoryFilter : t => string = "categoryFilter" [@@bs.get];

    external setTraceOptions : t => string => unit = "traceOptions" [@@bs.set];
    external getTraceOptions : t => string = "traceOptions" [@@bs.get];

  };

  let module CrashReporter = {
    type t;

    external start : t => CrashReporterStartOptions.t => unit = "" [@@bs.send];
    external getLastCrashReport : t => CrashReport.t = "" [@@bs.send];
    external getUploadedReports : t => (array CrashReport.t) = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module CrashReporterStartOptions = {
    type t;

    let module ExtraType = {
      type t;

      external value : t => string => string = "" [@@bs.send];
      external make : unit => t = "" [@@bs.obj];
    };

    external make : productName::string? => companyName::string => submitURL::string => autoSubmit::bool? => ignoreSystemCrashHandler::bool? => extra::ExtraType.t? => unit => t = "" [@@bs.obj];
    external setProductName : t => option string => unit = "productName" [@@bs.set];
    external getProductName : t => option string = "productName" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setCompanyName : t => string => unit = "companyName" [@@bs.set];
    external getCompanyName : t => string = "companyName" [@@bs.get];

    external setSubmitURL : t => string => unit = "submitURL" [@@bs.set];
    external getSubmitURL : t => string = "submitURL" [@@bs.get];

    external setAutoSubmit : t => option bool => unit = "autoSubmit" [@@bs.set];
    external getAutoSubmit : t => option bool = "autoSubmit" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIgnoreSystemCrashHandler : t => option bool => unit = "ignoreSystemCrashHandler" [@@bs.set];
    external getIgnoreSystemCrashHandler : t => option bool = "ignoreSystemCrashHandler" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setExtra : t => option ExtraType.t => unit = "extra" [@@bs.set];
    external getExtra : t => option ExtraType.t = "extra" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module CrashReport = {
    type t;

    external make : id::string => date::Date.t => t = "" [@@bs.obj];
    external setId : t => string => unit = "id" [@@bs.set];
    external getId : t => string = "id" [@@bs.get];

    external setDate : t => Date.t => unit = "date" [@@bs.set];
    external getDate : t => Date.t = "date" [@@bs.get];

  };

  let module DesktopCapturer = {
    type t;

    external getSources : t => DesktopCapturerOptions.t => (Error.t => (array DesktopCapturerSource.t) => 'a) => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module DesktopCapturerOptions = {
    type t;

    external make : types::(array 'a)? => thumbnailSize::Size.t? => unit => t = "" [@@bs.obj];
    external setTypes : t => option (array 'a) => unit = "types" [@@bs.set];
    external getTypes : t => option (array 'a) = "types" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setThumbnailSize : t => option Size.t => unit = "thumbnailSize" [@@bs.set];
    external getThumbnailSize : t => option Size.t = "thumbnailSize" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module DesktopCapturerSource = {
    type t;

    external make : id::string => name::string => thumbnail::NativeImage.t => t = "" [@@bs.obj];
    external setId : t => string => unit = "id" [@@bs.set];
    external getId : t => string = "id" [@@bs.get];

    external setName : t => string => unit = "name" [@@bs.set];
    external getName : t => string = "name" [@@bs.get];

    external setThumbnail : t => NativeImage.t => unit = "thumbnail" [@@bs.set];
    external getThumbnail : t => NativeImage.t = "thumbnail" [@@bs.get];

  };

  let module Dialog = {
    type t;

    external showOpenDialog0 : t => BrowserWindow.t => OpenDialogOptions.t => ((array string) => unit)? => unit => (array string) = "showOpenDialog" [@@bs.send];
    external showOpenDialog1 : t => OpenDialogOptions.t => ((array string) => unit)? => unit => (array string) = "showOpenDialog" [@@bs.send];
    external showSaveDialog0 : t => BrowserWindow.t => SaveDialogOptions.t => (string => unit)? => unit => string = "showSaveDialog" [@@bs.send];
    external showSaveDialog1 : t => SaveDialogOptions.t => (string => unit)? => unit => string = "showSaveDialog" [@@bs.send];
    external showMessageBox0 : t => BrowserWindow.t => ShowMessageBoxOptions.t => (float => unit)? => unit => float = "showMessageBox" [@@bs.send];
    external showMessageBox1 : t => ShowMessageBoxOptions.t => (float => unit)? => unit => float = "showMessageBox" [@@bs.send];
    external showErrorBox : t => string => string => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module OpenDialogOptions = {
    type t;

    let module FiltersType = {
      type t;

      external make : name::string => extensions::(array string) => t = "" [@@bs.obj];
      external setName : t => string => unit = "name" [@@bs.set];
      external getName : t => string = "name" [@@bs.get];

      external setExtensions : t => (array string) => unit = "extensions" [@@bs.set];
      external getExtensions : t => (array string) = "extensions" [@@bs.get];

    };

    external make : title::string? => defaultPath::string? => buttonLabel::string? => filters::(array FiltersType.t)? => properties::(array 'a)? => normalizeAccessKeys::bool? => message::string? => unit => t = "" [@@bs.obj];
    external setTitle : t => option string => unit = "title" [@@bs.set];
    external getTitle : t => option string = "title" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDefaultPath : t => option string => unit = "defaultPath" [@@bs.set];
    external getDefaultPath : t => option string = "defaultPath" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setButtonLabel : t => option string => unit = "buttonLabel" [@@bs.set];
    external getButtonLabel : t => option string = "buttonLabel" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setFilters : t => option (array FiltersType.t) => unit = "filters" [@@bs.set];
    external getFilters : t => option (array FiltersType.t) = "filters" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setProperties : t => option (array 'a) => unit = "properties" [@@bs.set];
    external getProperties : t => option (array 'a) = "properties" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setNormalizeAccessKeys : t => option bool => unit = "normalizeAccessKeys" [@@bs.set];
    external getNormalizeAccessKeys : t => option bool = "normalizeAccessKeys" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMessage : t => option string => unit = "message" [@@bs.set];
    external getMessage : t => option string = "message" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module SaveDialogOptions = {
    type t;

    let module FiltersType = {
      type t;

      external make : name::string => extensions::(array string) => t = "" [@@bs.obj];
      external setName : t => string => unit = "name" [@@bs.set];
      external getName : t => string = "name" [@@bs.get];

      external setExtensions : t => (array string) => unit = "extensions" [@@bs.set];
      external getExtensions : t => (array string) = "extensions" [@@bs.get];

    };

    external make : title::string? => defaultPath::string? => buttonLabel::string? => filters::(array FiltersType.t)? => message::string? => nameFieldLabel::string? => showsTagField::bool? => unit => t = "" [@@bs.obj];
    external setTitle : t => option string => unit = "title" [@@bs.set];
    external getTitle : t => option string = "title" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDefaultPath : t => option string => unit = "defaultPath" [@@bs.set];
    external getDefaultPath : t => option string = "defaultPath" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setButtonLabel : t => option string => unit = "buttonLabel" [@@bs.set];
    external getButtonLabel : t => option string = "buttonLabel" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setFilters : t => option (array FiltersType.t) => unit = "filters" [@@bs.set];
    external getFilters : t => option (array FiltersType.t) = "filters" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMessage : t => option string => unit = "message" [@@bs.set];
    external getMessage : t => option string = "message" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setNameFieldLabel : t => option string => unit = "nameFieldLabel" [@@bs.set];
    external getNameFieldLabel : t => option string = "nameFieldLabel" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setShowsTagField : t => option bool => unit = "showsTagField" [@@bs.set];
    external getShowsTagField : t => option bool = "showsTagField" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module ShowMessageBoxOptions = {
    type t;

    external make : type_::'a? => buttons::(array string)? => defaultId::float? => title::string? => message::string? => detail::string? => icon::NativeImage.t? => cancelId::float? => noLink::bool? => unit => t = "" [@@bs.obj];
    external setType : t => option 'a => unit = "type" [@@bs.set];
    external getType : t => option 'a = "type" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setButtons : t => option (array string) => unit = "buttons" [@@bs.set];
    external getButtons : t => option (array string) = "buttons" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDefaultId : t => option float => unit = "defaultId" [@@bs.set];
    external getDefaultId : t => option float = "defaultId" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setTitle : t => option string => unit = "title" [@@bs.set];
    external getTitle : t => option string = "title" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMessage : t => option string => unit = "message" [@@bs.set];
    external getMessage : t => option string = "message" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDetail : t => option string => unit = "detail" [@@bs.set];
    external getDetail : t => option string = "detail" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIcon : t => option NativeImage.t => unit = "icon" [@@bs.set];
    external getIcon : t => option NativeImage.t = "icon" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setCancelId : t => option float => unit = "cancelId" [@@bs.set];
    external getCancelId : t => option float = "cancelId" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setNoLink : t => option bool => unit = "noLink" [@@bs.set];
    external getNoLink : t => option bool = "noLink" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module DownloadItem = {
    type t;

    external onUpdated : t => (_ [@bs.as "updated"]) => (Event.t => 'a => unit) => t = "on" [@@bs.send];
    external onDone : t => (_ [@bs.as "done"]) => (Event.t => 'a => unit) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external setSavePath : t => string => unit = "" [@@bs.send];
    external getSavePath : t => string = "" [@@bs.send];
    external pause : t => unit = "" [@@bs.send];
    external isPaused : t => bool = "" [@@bs.send];
    external resume : t => unit = "" [@@bs.send];
    external canResume : t => bool = "" [@@bs.send];
    external cancel : t => unit = "" [@@bs.send];
    external getURL : t => string = "" [@@bs.send];
    external getMimeType : t => string = "" [@@bs.send];
    external hasUserGesture : t => bool = "" [@@bs.send];
    external getFilename : t => string = "" [@@bs.send];
    external getTotalBytes : t => float = "" [@@bs.send];
    external getReceivedBytes : t => float = "" [@@bs.send];
    external getContentDisposition : t => string = "" [@@bs.send];
    external getState : t => 'a = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module GlobalShortcut = {
    type t;

    external register : t => string => ('x => 'y) => unit = "" [@@bs.send];
    external isRegistered : t => string => bool = "" [@@bs.send];
    external unregister : t => string => unit = "" [@@bs.send];
    external unregisterAll : t => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module IpcMain = {
    type t;

    external addListener : t => string => IpcMainEventListener.t => t = "" [@@bs.send];
    external on : t => string => IpcMainEventListener.t => t = "" [@@bs.send];
    external once : t => string => IpcMainEventListener.t => t = "" [@@bs.send];
    external removeListener : t => string => IpcMainEventListener.t => t = "" [@@bs.send];
    external removeAllListeners : t => string? => unit => t = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module IpcMainEventListener = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module IpcMainEvent = {
    type t;

    external make : returnValue::'a? => sender::WebContents.t => unit => t = "" [@@bs.obj];
    external setReturnValue : t => option 'a => unit = "returnValue" [@@bs.set];
    external getReturnValue : t => option 'a = "returnValue" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSender : t => WebContents.t => unit = "sender" [@@bs.set];
    external getSender : t => WebContents.t = "sender" [@@bs.get];

  };

  let module IpcRenderer = {
    type t;

    external addListener : t => string => IpcRendererEventListener.t => t = "" [@@bs.send];
    external on : t => string => IpcRendererEventListener.t => t = "" [@@bs.send];
    external once : t => string => IpcRendererEventListener.t => t = "" [@@bs.send];
    external removeListener : t => string => IpcRendererEventListener.t => t = "" [@@bs.send];
    external removeAllListeners : t => string? => unit => t = "" [@@bs.send];
    external send : t => string => (array 'a) => unit = "" [@@bs.send];
    external sendSync : t => string => (array 'a) => 'a = "" [@@bs.send];
    external sendToHost : t => string => (array 'a) => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module IpcRendererEventListener = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module IpcRendererEvent = {
    type t;

    external make : sender::IpcRenderer.t => t = "" [@@bs.obj];
    external setSender : t => IpcRenderer.t => unit = "sender" [@@bs.set];
    external getSender : t => IpcRenderer.t = "sender" [@@bs.get];

  };

  let module MenuItem = {
    type t;

    external make : MenuItemOptions.t => t = "MenuItem" [@@bs.new] [@@bs.module "electron"];
    external setClick : t => (Event.t => BrowserWindow.t => WebContents.t => unit) => unit = "click" [@@bs.set];
    external getClick : t => (Event.t => BrowserWindow.t => WebContents.t => unit) = "click" [@@bs.get];

    external setType : t => MenuItemType.t => unit = "type" [@@bs.set];
    external getType : t => MenuItemType.t = "type" [@@bs.get];

    external setRole : t => 'a => unit = "role" [@@bs.set];
    external getRole : t => 'a = "role" [@@bs.get];

    external setAccelerator : t => string => unit = "accelerator" [@@bs.set];
    external getAccelerator : t => string = "accelerator" [@@bs.get];

    external setIcon : t => 'a => unit = "icon" [@@bs.set];
    external getIcon : t => 'a = "icon" [@@bs.get];

    external setSubmenu : t => 'a => unit = "submenu" [@@bs.set];
    external getSubmenu : t => 'a = "submenu" [@@bs.get];

    external setLabel : t => string => unit = "label" [@@bs.set];
    external getLabel : t => string = "label" [@@bs.get];

    external setSublabel : t => string => unit = "sublabel" [@@bs.set];
    external getSublabel : t => string = "sublabel" [@@bs.get];

    external setEnabled : t => bool => unit = "enabled" [@@bs.set];
    external getEnabled : t => bool = "enabled" [@@bs.get];

    external setVisible : t => bool => unit = "visible" [@@bs.set];
    external getVisible : t => bool = "visible" [@@bs.get];

    external setChecked : t => bool => unit = "checked" [@@bs.set];
    external getChecked : t => bool = "checked" [@@bs.get];

  };

  let module MenuItemType = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module MenuItemRole = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module MenuItemRoleMac = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module MenuItemOptions = {
    type t;

    external make : click::(MenuItem.t => BrowserWindow.t => Event.t => unit)? => type_::MenuItemType.t? => label::string? => sublabel::string? => accelerator::string? => icon::'a? => enabled::bool? => visible::bool? => checked::bool? => submenu::'a? => id::string? => position::string? => role::'a? => unit => t = "" [@@bs.obj];
    external setClick : t => option (MenuItem.t => BrowserWindow.t => Event.t => unit) => unit = "click" [@@bs.set];
    external getClick : t => option (MenuItem.t => BrowserWindow.t => Event.t => unit) = "click" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setType : t => option MenuItemType.t => unit = "type" [@@bs.set];
    external getType : t => option MenuItemType.t = "type" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLabel : t => option string => unit = "label" [@@bs.set];
    external getLabel : t => option string = "label" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSublabel : t => option string => unit = "sublabel" [@@bs.set];
    external getSublabel : t => option string = "sublabel" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAccelerator : t => option string => unit = "accelerator" [@@bs.set];
    external getAccelerator : t => option string = "accelerator" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIcon : t => option 'a => unit = "icon" [@@bs.set];
    external getIcon : t => option 'a = "icon" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setEnabled : t => option bool => unit = "enabled" [@@bs.set];
    external getEnabled : t => option bool = "enabled" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setVisible : t => option bool => unit = "visible" [@@bs.set];
    external getVisible : t => option bool = "visible" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setChecked : t => option bool => unit = "checked" [@@bs.set];
    external getChecked : t => option bool = "checked" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSubmenu : t => option 'a => unit = "submenu" [@@bs.set];
    external getSubmenu : t => option 'a = "submenu" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setId : t => option string => unit = "id" [@@bs.set];
    external getId : t => option string = "id" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPosition : t => option string => unit = "position" [@@bs.set];
    external getPosition : t => option string = "position" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setRole : t => option 'a => unit = "role" [@@bs.set];
    external getRole : t => option 'a = "role" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module Menu = {
    type t;

    external make : unit => t = "Menu" [@@bs.new] [@@bs.module "electron"];
    external setApplicationMenu : t => 'a => unit = "" [@@bs.send];
    external getApplicationMenu : t => 'a = "" [@@bs.send];
    external sendActionToFirstResponder : t => string => unit = "" [@@bs.send];
    external buildFromTemplate : t => (array MenuItemOptions.t) => Menu.t = "" [@@bs.send];
    external popup : t => BrowserWindow.t? => float? => float? => unit => unit = "" [@@bs.send];
    external append : t => MenuItem.t => unit = "" [@@bs.send];
    external insert : t => float => MenuItem.t => unit = "" [@@bs.send];
    external setItems : t => (array MenuItem.t) => unit = "items" [@@bs.set];
    external getItems : t => (array MenuItem.t) = "items" [@@bs.get];

  };

  let module NativeImage = {
    type t;

    external createEmpty : t => NativeImage.t = "" [@@bs.send];
    external createFromPath : t => string => NativeImage.t = "" [@@bs.send];
    external createFromBuffer : t => Buffer.t => float? => unit => NativeImage.t = "" [@@bs.send];
    external createFromDataURL : t => string => NativeImage.t = "" [@@bs.send];
    external toPNG : t => Buffer.t = "" [@@bs.send];
    external toJPEG : t => float => Buffer.t = "" [@@bs.send];
    external toBitmap : t => Buffer.t = "" [@@bs.send];
    external getBitmap : t => Buffer.t = "" [@@bs.send];
    external toDataURL : t => string = "" [@@bs.send];
    external getNativeHandle : t => Buffer.t = "" [@@bs.send];
    external isEmpty : t => bool = "" [@@bs.send];
    external getSize : t => Size.t = "" [@@bs.send];
    external setTemplateImage : t => bool => unit = "" [@@bs.send];
    external isTemplateImage : t => bool = "" [@@bs.send];
  };

  let module Net = {
    type t;

    external request : t => 'a => (IncomingMessage.t => unit)? => unit => ClientRequest.t = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module RequestOptions = {
    type t;

    let module HeadersType = {
      type t;

      external value : t => string => 'a = "" [@@bs.send];
      external make : unit => t = "" [@@bs.obj];
    };

    external make : method::string? => url::string? => session::Session.t? => partition::string? => protocol::'a? => host::string? => hostname::string? => port::float? => path::string? => headers::HeadersType.t? => unit => t = "" [@@bs.obj];
    external setMethod : t => option string => unit = "method" [@@bs.set];
    external getMethod : t => option string = "method" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setUrl : t => option string => unit = "url" [@@bs.set];
    external getUrl : t => option string = "url" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSession : t => option Session.t => unit = "session" [@@bs.set];
    external getSession : t => option Session.t = "session" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPartition : t => option string => unit = "partition" [@@bs.set];
    external getPartition : t => option string = "partition" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setProtocol : t => option 'a => unit = "protocol" [@@bs.set];
    external getProtocol : t => option 'a = "protocol" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHost : t => option string => unit = "host" [@@bs.set];
    external getHost : t => option string = "host" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHostname : t => option string => unit = "hostname" [@@bs.set];
    external getHostname : t => option string = "hostname" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPort : t => option float => unit = "port" [@@bs.set];
    external getPort : t => option float = "port" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPath : t => option string => unit = "path" [@@bs.set];
    external getPath : t => option string = "path" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHeaders : t => option HeadersType.t => unit = "headers" [@@bs.set];
    external getHeaders : t => option HeadersType.t = "headers" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module ClientRequest = {
    type t;

    external onResponse : t => (_ [@bs.as "response"]) => (IncomingMessage.t => unit) => t = "on" [@@bs.send];
    external onLogin : t => (_ [@bs.as "login"]) => (LoginAuthInfo.t => (string => string => unit) => unit) => t = "on" [@@bs.send];
    external onFinish : t => (_ [@bs.as "finish"]) => (unit => unit) => t = "on" [@@bs.send];
    external onAbort : t => (_ [@bs.as "abort"]) => (unit => unit) => t = "on" [@@bs.send];
    external onError : t => (_ [@bs.as "error"]) => (Error.t => unit) => t = "on" [@@bs.send];
    external onClose : t => (_ [@bs.as "close"]) => (unit => unit) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external make : 'a => (IncomingMessage.t => unit)? => unit => t = "ClientRequest" [@@bs.new] [@@bs.module "electron"];
    external setHeader : t => string => string => unit = "" [@@bs.send];
    external getHeader : t => string => string = "" [@@bs.send];
    external removeHeader : t => string => unit = "" [@@bs.send];
    external write : t => 'a => string? => ('x => 'y)? => unit => bool = "" [@@bs.send];
    external end : t => 'a? => string? => ('x => 'y)? => unit => bool = "" [@@bs.send];
    external abort : t => unit = "" [@@bs.send];
    external setChunkedEncoding : t => bool => unit = "chunkedEncoding" [@@bs.set];
    external getChunkedEncoding : t => bool = "chunkedEncoding" [@@bs.get];

  };

  let module IncomingMessage = {
    type t;

    let module HeadersType = {
      type t;

      external value : t => string => (array string) = "" [@@bs.send];
      external make : unit => t = "" [@@bs.obj];
    };

    external onData : t => (_ [@bs.as "data"]) => (Buffer.t => unit) => t = "on" [@@bs.send];
    external onEnd : t => (_ [@bs.as "end"]) => (unit => unit) => t = "on" [@@bs.send];
    external onAborted : t => (_ [@bs.as "aborted"]) => (unit => unit) => t = "on" [@@bs.send];
    external onError : t => (_ [@bs.as "error"]) => (Error.t => unit) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external make : statusCode::float => statusMessage::string => headers::HeadersType.t => httpVersion::string => httpVersionMajor::float => httpVersionMinor::float => t = "" [@@bs.obj];
    external setStatusCode : t => float => unit = "statusCode" [@@bs.set];
    external getStatusCode : t => float = "statusCode" [@@bs.get];

    external setStatusMessage : t => string => unit = "statusMessage" [@@bs.set];
    external getStatusMessage : t => string = "statusMessage" [@@bs.get];

    external setHeaders : t => HeadersType.t => unit = "headers" [@@bs.set];
    external getHeaders : t => HeadersType.t = "headers" [@@bs.get];

    external setHttpVersion : t => string => unit = "httpVersion" [@@bs.set];
    external getHttpVersion : t => string = "httpVersion" [@@bs.get];

    external setHttpVersionMajor : t => float => unit = "httpVersionMajor" [@@bs.set];
    external getHttpVersionMajor : t => float = "httpVersionMajor" [@@bs.get];

    external setHttpVersionMinor : t => float => unit = "httpVersionMinor" [@@bs.set];
    external getHttpVersionMinor : t => float = "httpVersionMinor" [@@bs.get];

  };

  let module PowerMonitor = {
    type t;

    external onSuspend : t => (_ [@bs.as "suspend"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onResume : t => (_ [@bs.as "resume"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onOnac : t => (_ [@bs.as "on-ac"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onOnbattery : t => (_ [@bs.as "on-battery"]) => ('x => 'y) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module PowerSaveBlocker = {
    type t;

    external start : t => 'a => float = "" [@@bs.send];
    external stop : t => float => unit = "" [@@bs.send];
    external isStarted : t => float => bool = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module Protocol = {
    type t;

    external registerStandardSchemes : t => (array string) => unit = "" [@@bs.send];
    external registerServiceWorkerSchemes : t => (array string) => unit = "" [@@bs.send];
    external registerFileProtocol : t => string => FileProtocolHandler.t => (Error.t => unit)? => unit => unit = "" [@@bs.send];
    external registerBufferProtocol : t => string => BufferProtocolHandler.t => (Error.t => unit)? => unit => unit = "" [@@bs.send];
    external registerStringProtocol : t => string => StringProtocolHandler.t => (Error.t => unit)? => unit => unit = "" [@@bs.send];
    external registerHttpProtocol : t => string => HttpProtocolHandler.t => (Error.t => unit)? => unit => unit = "" [@@bs.send];
    external unregisterProtocol : t => string => (Error.t => unit)? => unit => unit = "" [@@bs.send];
    external isProtocolHandled : t => string => (bool => unit) => unit = "" [@@bs.send];
    external interceptFileProtocol : t => string => FileProtocolHandler.t => (Error.t => unit)? => unit => unit = "" [@@bs.send];
    external interceptBufferProtocol : t => string => BufferProtocolHandler.t => (Error.t => unit)? => unit => unit = "" [@@bs.send];
    external interceptStringProtocol : t => string => StringProtocolHandler.t => (Error.t => unit)? => unit => unit = "" [@@bs.send];
    external interceptHttpProtocol : t => string => HttpProtocolHandler.t => (Error.t => unit)? => unit => unit = "" [@@bs.send];
    external uninterceptProtocol : t => string => (Error.t => unit)? => unit => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module FileProtocolHandler = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module BufferProtocolHandler = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module StringProtocolHandler = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module HttpProtocolHandler = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module ProtocolRequest = {
    type t;

    let module UploadDataType = {
      type t;

      external make : bytes::Buffer.t => file::string => blobUUID::string => t = "" [@@bs.obj];
      external setBytes : t => Buffer.t => unit = "bytes" [@@bs.set];
      external getBytes : t => Buffer.t = "bytes" [@@bs.get];

      external setFile : t => string => unit = "file" [@@bs.set];
      external getFile : t => string = "file" [@@bs.get];

      external setBlobUUID : t => string => unit = "blobUUID" [@@bs.set];
      external getBlobUUID : t => string = "blobUUID" [@@bs.get];

    };

    external make : url::string => referrer::string => method::string => uploadData::(array UploadDataType.t)? => unit => t = "" [@@bs.obj];
    external setUrl : t => string => unit = "url" [@@bs.set];
    external getUrl : t => string = "url" [@@bs.get];

    external setReferrer : t => string => unit = "referrer" [@@bs.set];
    external getReferrer : t => string = "referrer" [@@bs.get];

    external setMethod : t => string => unit = "method" [@@bs.set];
    external getMethod : t => string = "method" [@@bs.get];

    external setUploadData : t => option (array UploadDataType.t) => unit = "uploadData" [@@bs.set];
    external getUploadData : t => option (array UploadDataType.t) = "uploadData" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module ProtocolCallback = {
    type t;

    let module ObjType = {
      type t;

      external make : error::float => t = "" [@@bs.obj];
      external setError : t => float => unit = "error" [@@bs.set];
      external getError : t => float = "error" [@@bs.get];

    };

    external invoke0 : t => float => unit = "invoke" [@@bs.send];
    external invoke1 : t => ObjType.t => unit = "invoke" [@@bs.send];
    external invoke2 : t => unit = "invoke" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module FileProtocolCallback = {
    type t;

    let module ObjType = {
      type t;

      external make : path::string => t = "" [@@bs.obj];
      external setPath : t => string => unit = "path" [@@bs.set];
      external getPath : t => string = "path" [@@bs.get];

    };

    external invoke0 : t => string => unit = "invoke" [@@bs.send];
    external invoke1 : t => ObjType.t => unit = "invoke" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module BufferProtocolCallback = {
    type t;

    let module ObjType = {
      type t;

      external make : data::Buffer.t => mimeType::string => charset::string? => unit => t = "" [@@bs.obj];
      external setData : t => Buffer.t => unit = "data" [@@bs.set];
      external getData : t => Buffer.t = "data" [@@bs.get];

      external setMimeType : t => string => unit = "mimeType" [@@bs.set];
      external getMimeType : t => string = "mimeType" [@@bs.get];

      external setCharset : t => option string => unit = "charset" [@@bs.set];
      external getCharset : t => option string = "charset" [@@bs.get] [@@bs.return null_undefined_to_opt];

    };

    external invoke0 : t => Buffer.t => unit = "invoke" [@@bs.send];
    external invoke1 : t => ObjType.t => unit = "invoke" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module StringProtocolCallback = {
    type t;

    let module ObjType = {
      type t;

      external make : data::string => mimeType::string => charset::string? => unit => t = "" [@@bs.obj];
      external setData : t => string => unit = "data" [@@bs.set];
      external getData : t => string = "data" [@@bs.get];

      external setMimeType : t => string => unit = "mimeType" [@@bs.set];
      external getMimeType : t => string = "mimeType" [@@bs.get];

      external setCharset : t => option string => unit = "charset" [@@bs.set];
      external getCharset : t => option string = "charset" [@@bs.get] [@@bs.return null_undefined_to_opt];

    };

    external invoke0 : t => string => unit = "invoke" [@@bs.send];
    external invoke1 : t => ObjType.t => unit = "invoke" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module HttpProtocolCallback = {
    type t;

    let module RedirectRequestType = {
      type t;

      let module UploadDataType = {
        type t;

        external make : contentType::string => data::string => t = "" [@@bs.obj];
        external setContentType : t => string => unit = "contentType" [@@bs.set];
        external getContentType : t => string = "contentType" [@@bs.get];

        external setData : t => string => unit = "data" [@@bs.set];
        external getData : t => string = "data" [@@bs.get];

      };

      external make : url::string => method::string => session::Object.t? => uploadData::UploadDataType.t? => unit => t = "" [@@bs.obj];
      external setUrl : t => string => unit = "url" [@@bs.set];
      external getUrl : t => string = "url" [@@bs.get];

      external setMethod : t => string => unit = "method" [@@bs.set];
      external getMethod : t => string = "method" [@@bs.get];

      external setSession : t => option Object.t => unit = "session" [@@bs.set];
      external getSession : t => option Object.t = "session" [@@bs.get] [@@bs.return null_undefined_to_opt];

      external setUploadData : t => option UploadDataType.t => unit = "uploadData" [@@bs.set];
      external getUploadData : t => option UploadDataType.t = "uploadData" [@@bs.get] [@@bs.return null_undefined_to_opt];

    };

    external invoke : t => RedirectRequestType.t => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module Remote = {
    type t;

    external require : t => string => 'a = "" [@@bs.send];
    external getCurrentWindow : t => BrowserWindow.t = "" [@@bs.send];
    external getCurrentWebContents : t => WebContents.t = "" [@@bs.send];
    external getGlobal : t => string => 'a = "" [@@bs.send];
    external make : process::NodeJS.Process.t => t = "" [@@bs.obj];
    external setProcess : t => NodeJS.Process.t => unit = "process" [@@bs.set];
    external getProcess : t => NodeJS.Process.t = "process" [@@bs.get];

  };

  let module Display = {
    type t;

    external make : id::float => bounds::Rectangle.t => workArea::Rectangle.t => size::Size.t => workAreaSize::Size.t => scaleFactor::float => rotation::float => touchSupport::'a => t = "" [@@bs.obj];
    external setId : t => float => unit = "id" [@@bs.set];
    external getId : t => float = "id" [@@bs.get];

    external setBounds : t => Rectangle.t => unit = "bounds" [@@bs.set];
    external getBounds : t => Rectangle.t = "bounds" [@@bs.get];

    external setWorkArea : t => Rectangle.t => unit = "workArea" [@@bs.set];
    external getWorkArea : t => Rectangle.t = "workArea" [@@bs.get];

    external setSize : t => Size.t => unit = "size" [@@bs.set];
    external getSize : t => Size.t = "size" [@@bs.get];

    external setWorkAreaSize : t => Size.t => unit = "workAreaSize" [@@bs.set];
    external getWorkAreaSize : t => Size.t = "workAreaSize" [@@bs.get];

    external setScaleFactor : t => float => unit = "scaleFactor" [@@bs.set];
    external getScaleFactor : t => float = "scaleFactor" [@@bs.get];

    external setRotation : t => float => unit = "rotation" [@@bs.set];
    external getRotation : t => float = "rotation" [@@bs.get];

    external setTouchSupport : t => 'a => unit = "touchSupport" [@@bs.set];
    external getTouchSupport : t => 'a = "touchSupport" [@@bs.get];

  };

  let module DisplayMetrics = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module Screen = {
    type t;

    external onDisplayadded : t => (_ [@bs.as "display-added"]) => (Event.t => Display.t => unit) => t = "on" [@@bs.send];
    external onDisplayremoved : t => (_ [@bs.as "display-removed"]) => (Event.t => Display.t => unit) => t = "on" [@@bs.send];
    external onDisplaymetricschanged : t => (_ [@bs.as "display-metrics-changed"]) => (Event.t => Display.t => (array DisplayMetrics.t) => unit) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external getCursorScreenPoint : t => Point.t = "" [@@bs.send];
    external getPrimaryDisplay : t => Display.t = "" [@@bs.send];
    external getAllDisplays : t => (array Display.t) = "" [@@bs.send];
    external getDisplayNearestPoint : t => Point.t => Display.t = "" [@@bs.send];
    external getDisplayMatching : t => Rectangle.t => Display.t = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module Session = {
    type t;

    external fromPartition : t => string => FromPartitionOptions.t? => unit => Session.t = "" [@@bs.send];
    external onWilldownload : t => (_ [@bs.as "will-download"]) => (Event.t => DownloadItem.t => WebContents.t => unit) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external getCacheSize : t => (float => unit) => unit = "" [@@bs.send];
    external clearCache : t => ('x => 'y) => unit = "" [@@bs.send];
    external clearStorageData0 : t => ('x => 'y) => unit = "clearStorageData" [@@bs.send];
    external clearStorageData1 : t => ClearStorageDataOptions.t => ('x => 'y) => unit = "clearStorageData" [@@bs.send];
    external flushStorageData : t => unit = "" [@@bs.send];
    external setProxy : t => ProxyConfig.t => ('x => 'y) => unit = "" [@@bs.send];
    external resolveProxy : t => URL.t => (string => unit) => unit = "" [@@bs.send];
    external setDownloadPath : t => string => unit = "" [@@bs.send];
    external enableNetworkEmulation : t => NetworkEmulationOptions.t => unit = "" [@@bs.send];
    external disableNetworkEmulation : t => unit = "" [@@bs.send];
    external setCertificateVerifyProc : t => 'a => unit = "" [@@bs.send];
    external setPermissionRequestHandler : t => (WebContents.t => Permission.t => (bool => unit) => unit) => unit = "" [@@bs.send];
    external clearHostResolverCache : t => ('x => 'y) => unit = "" [@@bs.send];
    external allowNTLMCredentialsForDomains : t => string => unit = "" [@@bs.send];
    external setUserAgent : t => string => string? => unit => unit = "" [@@bs.send];
    external getUserAgent : t => string = "" [@@bs.send];
    external getBlobData : t => string => (Buffer.t => unit) => unit = "" [@@bs.send];
    external setDefaultSession : t => Session.t => unit = "defaultSession" [@@bs.set];
    external getDefaultSession : t => Session.t = "defaultSession" [@@bs.get];

    external setCookies : t => SessionCookies.t => unit = "cookies" [@@bs.set];
    external getCookies : t => SessionCookies.t = "cookies" [@@bs.get];

    external setWebRequest : t => WebRequest.t => unit = "webRequest" [@@bs.set];
    external getWebRequest : t => WebRequest.t = "webRequest" [@@bs.get];

    external setProtocol : t => Protocol.t => unit = "protocol" [@@bs.set];
    external getProtocol : t => Protocol.t = "protocol" [@@bs.get];

  };

  let module Permission = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module FromPartitionOptions = {
    type t;

    external make : cache::bool? => unit => t = "" [@@bs.obj];
    external setCache : t => option bool => unit = "cache" [@@bs.set];
    external getCache : t => option bool = "cache" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module ClearStorageDataOptions = {
    type t;

    external make : origin::string? => storages::(array 'a)? => quotas::(array 'a)? => unit => t = "" [@@bs.obj];
    external setOrigin : t => option string => unit = "origin" [@@bs.set];
    external getOrigin : t => option string = "origin" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setStorages : t => option (array 'a) => unit = "storages" [@@bs.set];
    external getStorages : t => option (array 'a) = "storages" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setQuotas : t => option (array 'a) => unit = "quotas" [@@bs.set];
    external getQuotas : t => option (array 'a) = "quotas" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module ProxyConfig = {
    type t;

    external make : pacScript::string => proxyRules::string => proxyBypassRules::string => t = "" [@@bs.obj];
    external setPacScript : t => string => unit = "pacScript" [@@bs.set];
    external getPacScript : t => string = "pacScript" [@@bs.get];

    external setProxyRules : t => string => unit = "proxyRules" [@@bs.set];
    external getProxyRules : t => string = "proxyRules" [@@bs.get];

    external setProxyBypassRules : t => string => unit = "proxyBypassRules" [@@bs.set];
    external getProxyBypassRules : t => string = "proxyBypassRules" [@@bs.get];

  };

  let module NetworkEmulationOptions = {
    type t;

    external make : offline::bool? => latency::float? => downloadThroughput::float? => uploadThroughput::float? => unit => t = "" [@@bs.obj];
    external setOffline : t => option bool => unit = "offline" [@@bs.set];
    external getOffline : t => option bool = "offline" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLatency : t => option float => unit = "latency" [@@bs.set];
    external getLatency : t => option float = "latency" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDownloadThroughput : t => option float => unit = "downloadThroughput" [@@bs.set];
    external getDownloadThroughput : t => option float = "downloadThroughput" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setUploadThroughput : t => option float => unit = "uploadThroughput" [@@bs.set];
    external getUploadThroughput : t => option float = "uploadThroughput" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module CookieFilter = {
    type t;

    external make : url::string? => name::string? => domain::string? => path::string? => secure::bool? => session::bool? => unit => t = "" [@@bs.obj];
    external setUrl : t => option string => unit = "url" [@@bs.set];
    external getUrl : t => option string = "url" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setName : t => option string => unit = "name" [@@bs.set];
    external getName : t => option string = "name" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDomain : t => option string => unit = "domain" [@@bs.set];
    external getDomain : t => option string = "domain" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPath : t => option string => unit = "path" [@@bs.set];
    external getPath : t => option string = "path" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSecure : t => option bool => unit = "secure" [@@bs.set];
    external getSecure : t => option bool = "secure" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSession : t => option bool => unit = "session" [@@bs.set];
    external getSession : t => option bool = "session" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module Cookie = {
    type t;

    external onChanged : t => (_ [@bs.as "changed"]) => (Event.t => Cookie.t => CookieChangedCause.t => unit) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external make : name::string => value::string => domain::string => hostOnly::string => path::string => secure::bool => httpOnly::bool => session::bool => expirationDate::float? => unit => t = "" [@@bs.obj];
    external setName : t => string => unit = "name" [@@bs.set];
    external getName : t => string = "name" [@@bs.get];

    external setValue : t => string => unit = "value" [@@bs.set];
    external getValue : t => string = "value" [@@bs.get];

    external setDomain : t => string => unit = "domain" [@@bs.set];
    external getDomain : t => string = "domain" [@@bs.get];

    external setHostOnly : t => string => unit = "hostOnly" [@@bs.set];
    external getHostOnly : t => string = "hostOnly" [@@bs.get];

    external setPath : t => string => unit = "path" [@@bs.set];
    external getPath : t => string = "path" [@@bs.get];

    external setSecure : t => bool => unit = "secure" [@@bs.set];
    external getSecure : t => bool = "secure" [@@bs.get];

    external setHttpOnly : t => bool => unit = "httpOnly" [@@bs.set];
    external getHttpOnly : t => bool = "httpOnly" [@@bs.get];

    external setSession : t => bool => unit = "session" [@@bs.set];
    external getSession : t => bool = "session" [@@bs.get];

    external setExpirationDate : t => option float => unit = "expirationDate" [@@bs.set];
    external getExpirationDate : t => option float = "expirationDate" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module CookieChangedCause = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module CookieDetails = {
    type t;

    external make : url::string => name::string? => value::string? => domain::string? => path::string? => secure::bool? => httpOnly::bool? => expirationDate::float? => unit => t = "" [@@bs.obj];
    external setUrl : t => string => unit = "url" [@@bs.set];
    external getUrl : t => string = "url" [@@bs.get];

    external setName : t => option string => unit = "name" [@@bs.set];
    external getName : t => option string = "name" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setValue : t => option string => unit = "value" [@@bs.set];
    external getValue : t => option string = "value" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDomain : t => option string => unit = "domain" [@@bs.set];
    external getDomain : t => option string = "domain" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPath : t => option string => unit = "path" [@@bs.set];
    external getPath : t => option string = "path" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSecure : t => option bool => unit = "secure" [@@bs.set];
    external getSecure : t => option bool = "secure" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHttpOnly : t => option bool => unit = "httpOnly" [@@bs.set];
    external getHttpOnly : t => option bool = "httpOnly" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setExpirationDate : t => option float => unit = "expirationDate" [@@bs.set];
    external getExpirationDate : t => option float = "expirationDate" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module SessionCookies = {
    type t;

    external get : t => CookieFilter.t => (Error.t => (array Cookie.t) => unit) => unit = "" [@@bs.send];
    external set : t => CookieDetails.t => (Error.t => unit) => unit = "" [@@bs.send];
    external remove : t => string => string => (Error.t => unit) => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module WebRequest = {
    type t;

    external onBeforeRequest0 : t => (WebRequest.BeforeRequestDetails.t => WebRequest.BeforeRequestCallback.t => unit) => unit = "onBeforeRequest" [@@bs.send];
    external onBeforeRequest1 : t => WebRequest.Filter.t => (WebRequest.BeforeRequestDetails.t => WebRequest.BeforeRequestCallback.t => unit) => unit = "onBeforeRequest" [@@bs.send];
    external onBeforeSendHeaders0 : t => (WebRequest.BeforeSendHeadersDetails.t => WebRequest.BeforeSendHeadersCallback.t => unit) => unit = "onBeforeSendHeaders" [@@bs.send];
    external onBeforeSendHeaders1 : t => WebRequest.Filter.t => (WebRequest.BeforeSendHeadersDetails.t => WebRequest.BeforeSendHeadersCallback.t => unit) => unit = "onBeforeSendHeaders" [@@bs.send];
    external onSendHeaders0 : t => (WebRequest.SendHeadersDetails.t => unit) => unit = "onSendHeaders" [@@bs.send];
    external onSendHeaders1 : t => WebRequest.Filter.t => (WebRequest.SendHeadersDetails.t => unit) => unit = "onSendHeaders" [@@bs.send];
    external onHeadersReceived0 : t => (WebRequest.HeadersReceivedDetails.t => WebRequest.HeadersReceivedCallback.t => unit) => unit = "onHeadersReceived" [@@bs.send];
    external onHeadersReceived1 : t => WebRequest.Filter.t => (WebRequest.HeadersReceivedDetails.t => WebRequest.HeadersReceivedCallback.t => unit) => unit = "onHeadersReceived" [@@bs.send];
    external onResponseStarted0 : t => (WebRequest.ResponseStartedDetails.t => unit) => unit = "onResponseStarted" [@@bs.send];
    external onResponseStarted1 : t => WebRequest.Filter.t => (WebRequest.ResponseStartedDetails.t => unit) => unit = "onResponseStarted" [@@bs.send];
    external onBeforeRedirect0 : t => (WebRequest.BeforeRedirectDetails.t => unit) => unit = "onBeforeRedirect" [@@bs.send];
    external onBeforeRedirect1 : t => WebRequest.Filter.t => (WebRequest.BeforeRedirectDetails.t => unit) => unit = "onBeforeRedirect" [@@bs.send];
    external onCompleted0 : t => (WebRequest.CompletedDetails.t => unit) => unit = "onCompleted" [@@bs.send];
    external onCompleted1 : t => WebRequest.Filter.t => (WebRequest.CompletedDetails.t => unit) => unit = "onCompleted" [@@bs.send];
    external onErrorOccurred0 : t => (WebRequest.ErrorOccurredDetails.t => unit) => unit = "onErrorOccurred" [@@bs.send];
    external onErrorOccurred1 : t => WebRequest.Filter.t => (WebRequest.ErrorOccurredDetails.t => unit) => unit = "onErrorOccurred" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module Shell = {
    type t;

    let module OptionsType = {
      type t;

      external make : activate::bool => t = "" [@@bs.obj];
      external setActivate : t => bool => unit = "activate" [@@bs.set];
      external getActivate : t => bool = "activate" [@@bs.get];

    };

    external showItemInFolder : t => string => bool = "" [@@bs.send];
    external openItem : t => string => bool = "" [@@bs.send];
    external openExternal : t => string => OptionsType.t? => unit => bool = "" [@@bs.send];
    external moveItemToTrash : t => string => bool = "" [@@bs.send];
    external beep : t => unit = "" [@@bs.send];
    external writeShortcutLink0 : t => string => ShortcutLinkOptions.t => bool = "writeShortcutLink" [@@bs.send];
    external writeShortcutLink1 : t => string => 'a => ShortcutLinkOptions.t => bool = "writeShortcutLink" [@@bs.send];
    external readShortcutLink : t => string => ShortcutLinkOptions.t = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module ShortcutLinkOptions = {
    type t;

    external make : target::string => cwd::string? => args::string? => description::string? => icon::string? => iconIndex::float? => appUserModelId::string? => unit => t = "" [@@bs.obj];
    external setTarget : t => string => unit = "target" [@@bs.set];
    external getTarget : t => string = "target" [@@bs.get];

    external setCwd : t => option string => unit = "cwd" [@@bs.set];
    external getCwd : t => option string = "cwd" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setArgs : t => option string => unit = "args" [@@bs.set];
    external getArgs : t => option string = "args" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDescription : t => option string => unit = "description" [@@bs.set];
    external getDescription : t => option string = "description" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIcon : t => option string => unit = "icon" [@@bs.set];
    external getIcon : t => option string = "icon" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIconIndex : t => option float => unit = "iconIndex" [@@bs.set];
    external getIconIndex : t => option float = "iconIndex" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAppUserModelId : t => option string => unit = "appUserModelId" [@@bs.set];
    external getAppUserModelId : t => option string = "appUserModelId" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module SystemColor = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module SystemPreferences = {
    type t;

    external onAccentcolorchanged : t => (_ [@bs.as "accent-color-changed"]) => (Event.t => string => unit) => t = "on" [@@bs.send];
    external onColorchanged : t => (_ [@bs.as "color-changed"]) => (Event.t => unit) => t = "on" [@@bs.send];
    external onInvertedcolorschemechanged : t => (_ [@bs.as "inverted-color-scheme-changed"]) => (Event.t => bool => unit) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external isDarkMode : t => bool = "" [@@bs.send];
    external isSwipeTrackingFromScrollEventsEnabled : t => bool = "" [@@bs.send];
    external postNotification : t => string => Object.t => unit = "" [@@bs.send];
    external postLocalNotification : t => string => Object.t => unit = "" [@@bs.send];
    external subscribeNotification : t => string => (Event.t => Object.t => unit) => float = "" [@@bs.send];
    external unsubscribeNotification : t => float => unit = "" [@@bs.send];
    external subscribeLocalNotification : t => string => (Event.t => Object.t => unit) => float = "" [@@bs.send];
    external unsubscribeLocalNotification : t => float => unit = "" [@@bs.send];
    external getUserDefault : t => string => 'a => 'a = "" [@@bs.send];
    external isAeroGlassEnabled : t => bool = "" [@@bs.send];
    external getAccentColor : t => string = "" [@@bs.send];
    external isInvertedColorScheme : t => bool = "" [@@bs.send];
    external getColor : t => SystemColor.t => string = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module Tray = {
    type t;

    let module OptionsType = {
      type t;

      external make : icon::NativeImage.t? => title::string? => content::string? => unit => t = "" [@@bs.obj];
      external setIcon : t => option NativeImage.t => unit = "icon" [@@bs.set];
      external getIcon : t => option NativeImage.t = "icon" [@@bs.get] [@@bs.return null_undefined_to_opt];

      external setTitle : t => option string => unit = "title" [@@bs.set];
      external getTitle : t => option string = "title" [@@bs.get] [@@bs.return null_undefined_to_opt];

      external setContent : t => option string => unit = "content" [@@bs.set];
      external getContent : t => option string = "content" [@@bs.get] [@@bs.return null_undefined_to_opt];

    };

    external onClick : t => (_ [@bs.as "click"]) => (Modifiers.t => Rectangle.t => unit) => t = "on" [@@bs.send];
    external onRightclick : t => (_ [@bs.as "right-click"]) => (Modifiers.t => Rectangle.t => unit) => t = "on" [@@bs.send];
    external onDoubleclick : t => (_ [@bs.as "double-click"]) => (Modifiers.t => Rectangle.t => unit) => t = "on" [@@bs.send];
    external onBalloonshow : t => (_ [@bs.as "balloon-show"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onBalloonclick : t => (_ [@bs.as "balloon-click"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onBalloonclosed : t => (_ [@bs.as "balloon-closed"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onDrop : t => (_ [@bs.as "drop"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onDropfiles : t => (_ [@bs.as "drop-files"]) => (Event.t => (array string) => unit) => t = "on" [@@bs.send];
    external onDroptext : t => (_ [@bs.as "drop-text"]) => (Event.t => string => unit) => t = "on" [@@bs.send];
    external onDragenter : t => (_ [@bs.as "drag-enter"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onDragleave : t => (_ [@bs.as "drag-leave"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onDragend : t => (_ [@bs.as "drag-end"]) => ('x => 'y) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external make : 'a => t = "Tray" [@@bs.new] [@@bs.module "electron"];
    external destroy : t => unit = "" [@@bs.send];
    external setImage : t => 'a => unit = "" [@@bs.send];
    external setPressedImage : t => NativeImage.t => unit = "" [@@bs.send];
    external setToolTip : t => string => unit = "" [@@bs.send];
    external setTitle : t => string => unit = "" [@@bs.send];
    external setHighlightMode : t => 'a => unit = "" [@@bs.send];
    external displayBalloon : t => OptionsType.t? => unit => unit = "" [@@bs.send];
    external popUpContextMenu : t => Menu.t? => Point.t? => unit => unit = "" [@@bs.send];
    external setContextMenu : t => Menu.t => unit = "" [@@bs.send];
    external getBounds : t => Rectangle.t = "" [@@bs.send];
    external isDestroyed : t => bool = "" [@@bs.send];
  };

  let module Modifiers = {
    type t;

    external make : altKey::bool => shiftKey::bool => ctrlKey::bool => metaKey::bool => t = "" [@@bs.obj];
    external setAltKey : t => bool => unit = "altKey" [@@bs.set];
    external getAltKey : t => bool = "altKey" [@@bs.get];

    external setShiftKey : t => bool => unit = "shiftKey" [@@bs.set];
    external getShiftKey : t => bool = "shiftKey" [@@bs.get];

    external setCtrlKey : t => bool => unit = "ctrlKey" [@@bs.set];
    external getCtrlKey : t => bool = "ctrlKey" [@@bs.get];

    external setMetaKey : t => bool => unit = "metaKey" [@@bs.set];
    external getMetaKey : t => bool = "metaKey" [@@bs.get];

  };

  let module DragItem = {
    type t;

    external make : file::string => icon::NativeImage.t => t = "" [@@bs.obj];
    external setFile : t => string => unit = "file" [@@bs.set];
    external getFile : t => string = "file" [@@bs.get];

    external setIcon : t => NativeImage.t => unit = "icon" [@@bs.set];
    external getIcon : t => NativeImage.t = "icon" [@@bs.get];

  };

  let module WebContentsStatic = {
    type t;

    external getAllWebContents : t => (array WebContents.t) = "" [@@bs.send];
    external getFocusedWebContents : t => WebContents.t = "" [@@bs.send];
    external fromId : t => float => WebContents.t = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module WebContents = {
    type t;

    let module OptionsType = {
      type t;

      external make : mode::'a? => unit => t = "" [@@bs.obj];
      external setMode : t => option 'a => unit = "mode" [@@bs.set];
      external getMode : t => option 'a = "mode" [@@bs.get] [@@bs.return null_undefined_to_opt];

    };

    external onDidfinishload : t => (_ [@bs.as "did-finish-load"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onDidfailload : t => (_ [@bs.as "did-fail-load"]) => (Event.t => float => string => string => bool => unit) => t = "on" [@@bs.send];
    external onDidframefinishload : t => (_ [@bs.as "did-frame-finish-load"]) => (Event.t => bool => unit) => t = "on" [@@bs.send];
    external onDidstartloading : t => (_ [@bs.as "did-start-loading"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onDidstoploading : t => (_ [@bs.as "did-stop-loading"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onDidgetresponsedetails : t => (_ [@bs.as "did-get-response-details"]) => (Event.t => bool => string => string => float => string => string => Headers.t => string => unit) => t = "on" [@@bs.send];
    external onDidgetredirectrequest : t => (_ [@bs.as "did-get-redirect-request"]) => (Event.t => string => string => bool => float => string => string => Headers.t => unit) => t = "on" [@@bs.send];
    external onDomready : t => (_ [@bs.as "dom-ready"]) => (Event.t => unit) => t = "on" [@@bs.send];
    external onPagefaviconupdated : t => (_ [@bs.as "page-favicon-updated"]) => (Event.t => (array string) => unit) => t = "on" [@@bs.send];
    external onNewwindow : t => (_ [@bs.as "new-window"]) => (Event.t => string => string => NewWindowDisposition.t => BrowserWindowOptions.t => unit) => t = "on" [@@bs.send];
    external onWillnavigate : t => (_ [@bs.as "will-navigate"]) => (Event.t => string => unit) => t = "on" [@@bs.send];
    external onDidnavigate : t => (_ [@bs.as "did-navigate"]) => (Event.t => string => unit) => t = "on" [@@bs.send];
    external onDidnavigateinpage : t => (_ [@bs.as "did-navigate-in-page"]) => (Event.t => string => bool => unit) => t = "on" [@@bs.send];
    external onCrashed : t => (_ [@bs.as "crashed"]) => (Event.t => bool => unit) => t = "on" [@@bs.send];
    external onPlugincrashed : t => (_ [@bs.as "plugin-crashed"]) => (Event.t => string => string => unit) => t = "on" [@@bs.send];
    external onDestroyed : t => (_ [@bs.as "destroyed"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onDevtoolsopened : t => (_ [@bs.as "devtools-opened"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onDevtoolsclosed : t => (_ [@bs.as "devtools-closed"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onDevtoolsfocused : t => (_ [@bs.as "devtools-focused"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onCertificateerror : t => (_ [@bs.as "certificate-error"]) => (Event.t => string => string => Certificate.t => (bool => unit) => unit) => t = "on" [@@bs.send];
    external onSelectclientcertificate : t => (_ [@bs.as "select-client-certificate"]) => (Event.t => string => (array Certificate.t) => (Certificate.t => unit) => unit) => t = "on" [@@bs.send];
    external onLogin : t => (_ [@bs.as "login"]) => (Event.t => LoginRequest.t => LoginAuthInfo.t => (string => string => unit) => unit) => t = "on" [@@bs.send];
    external onFoundinpage : t => (_ [@bs.as "found-in-page"]) => (Event.t => FoundInPageResult.t => unit) => t = "on" [@@bs.send];
    external onMediastartedplaying : t => (_ [@bs.as "media-started-playing"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onMediapaused : t => (_ [@bs.as "media-paused"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onDidchangethemecolor : t => (_ [@bs.as "did-change-theme-color"]) => ('x => 'y) => t = "on" [@@bs.send];
    external onUpdatetargeturl : t => (_ [@bs.as "update-target-url"]) => (Event.t => string => unit) => t = "on" [@@bs.send];
    external onCursorchanged : t => (_ [@bs.as "cursor-changed"]) => (Event.t => CursorType.t => NativeImage.t => float => Size.t => Point.t => unit) => t = "on" [@@bs.send];
    external onContextmenu : t => (_ [@bs.as "context-menu"]) => (Event.t => ContextMenuParams.t => unit) => t = "on" [@@bs.send];
    external onSelectbluetoothdevice : t => (_ [@bs.as "select-bluetooth-device"]) => (Event.t => (array BluetoothDevice.t) => (string => unit) => unit) => t = "on" [@@bs.send];
    external onPaint : t => (_ [@bs.as "paint"]) => (Event.t => Rectangle.t => NativeImage.t => unit) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external loadURL : t => string => LoadURLOptions.t? => unit => unit = "" [@@bs.send];
    external downloadURL : t => string => unit = "" [@@bs.send];
    external getURL : t => string = "" [@@bs.send];
    external getTitle : t => string = "" [@@bs.send];
    external isDestroyed : t => bool = "" [@@bs.send];
    external isFocused : t => bool = "" [@@bs.send];
    external isLoading : t => bool = "" [@@bs.send];
    external isLoadingMainFrame : t => bool = "" [@@bs.send];
    external isWaitingForResponse : t => bool = "" [@@bs.send];
    external stop : t => unit = "" [@@bs.send];
    external reload : t => unit = "" [@@bs.send];
    external reloadIgnoringCache : t => unit = "" [@@bs.send];
    external canGoBack : t => bool = "" [@@bs.send];
    external canGoForward : t => bool = "" [@@bs.send];
    external canGoToOffset : t => float => bool = "" [@@bs.send];
    external clearHistory : t => unit = "" [@@bs.send];
    external goBack : t => unit = "" [@@bs.send];
    external goForward : t => unit = "" [@@bs.send];
    external goToIndex : t => float => unit = "" [@@bs.send];
    external goToOffset : t => float => unit = "" [@@bs.send];
    external isCrashed : t => bool = "" [@@bs.send];
    external setUserAgent : t => string => unit = "" [@@bs.send];
    external getUserAgent : t => string = "" [@@bs.send];
    external insertCSS : t => string => unit = "" [@@bs.send];
    external executeJavaScript : t => string => bool? => ('a => unit)? => unit => Promise.t ('a) = "" [@@bs.send];
    external setAudioMuted : t => bool => unit = "" [@@bs.send];
    external isAudioMuted : t => bool = "" [@@bs.send];
    external setZoomFactor : t => float => unit = "" [@@bs.send];
    external getZoomFactor : t => (float => unit) => unit = "" [@@bs.send];
    external setZoomLevel : t => float => unit = "" [@@bs.send];
    external getZoomLevel : t => (float => unit) => unit = "" [@@bs.send];
    external setVisualZoomLevelLimits : t => float => float => unit = "" [@@bs.send];
    external setLayoutZoomLevelLimits : t => float => float => unit = "" [@@bs.send];
    external undo : t => unit = "" [@@bs.send];
    external redo : t => unit = "" [@@bs.send];
    external cut : t => unit = "" [@@bs.send];
    external copy : t => unit = "" [@@bs.send];
    external copyImageAt : t => float => float => unit = "" [@@bs.send];
    external paste : t => unit = "" [@@bs.send];
    external pasteAndMatchStyle : t => unit = "" [@@bs.send];
    external delete : t => unit = "" [@@bs.send];
    external selectAll : t => unit = "" [@@bs.send];
    external unselect : t => unit = "" [@@bs.send];
    external replace : t => string => unit = "" [@@bs.send];
    external replaceMisspelling : t => string => unit = "" [@@bs.send];
    external insertText : t => string => unit = "" [@@bs.send];
    external findInPage : t => string => FindInPageOptions.t? => unit => float = "" [@@bs.send];
    external stopFindInPage : t => StopFindInPageAtion.t => unit = "" [@@bs.send];
    external hasServiceWorker : t => (bool => unit) => unit = "" [@@bs.send];
    external unregisterServiceWorker : t => (bool => unit) => unit = "" [@@bs.send];
    external print : t => PrintOptions.t? => unit => unit = "" [@@bs.send];
    external printToPDF : t => PrintToPDFOptions.t => (Error.t => Buffer.t => unit) => unit = "" [@@bs.send];
    external addWorkSpace : t => string => unit = "" [@@bs.send];
    external removeWorkSpace : t => string => unit = "" [@@bs.send];
    external openDevTools : t => OptionsType.t? => unit => unit = "" [@@bs.send];
    external closeDevTools : t => unit = "" [@@bs.send];
    external isDevToolsOpened : t => bool = "" [@@bs.send];
    external isDevToolsFocused : t => bool = "" [@@bs.send];
    external toggleDevTools : t => unit = "" [@@bs.send];
    external inspectElement : t => float => float => unit = "" [@@bs.send];
    external inspectServiceWorker : t => unit = "" [@@bs.send];
    external send : t => string => (array 'a) => unit = "" [@@bs.send];
    external enableDeviceEmulation : t => DeviceEmulationParameters.t => unit = "" [@@bs.send];
    external disableDeviceEmulation : t => unit = "" [@@bs.send];
    external sendInputEvent : t => SendInputEvent.t => unit = "" [@@bs.send];
    external beginFrameSubscription0 : t => bool => BeginFrameSubscriptionCallback.t => unit = "beginFrameSubscription" [@@bs.send];
    external beginFrameSubscription1 : t => BeginFrameSubscriptionCallback.t => unit = "beginFrameSubscription" [@@bs.send];
    external endFrameSubscription : t => unit = "" [@@bs.send];
    external savePage : t => string => 'a => (Error.t => unit)? => unit => bool = "" [@@bs.send];
    external showDefinitionForSelection : t => unit = "" [@@bs.send];
    external isOffscreen : t => bool = "" [@@bs.send];
    external startPainting : t => unit = "" [@@bs.send];
    external stopPainting : t => unit = "" [@@bs.send];
    external isPainting : t => bool = "" [@@bs.send];
    external setFrameRate : t => float => unit = "" [@@bs.send];
    external getFrameRate : t => float = "" [@@bs.send];
    external invalidate : t => unit = "" [@@bs.send];
    external startDrag : t => DragItem.t => unit = "" [@@bs.send];
    external capturePage0 : t => (NativeImage.t => unit) => unit = "capturePage" [@@bs.send];
    external capturePage1 : t => Rectangle.t => (NativeImage.t => unit) => unit = "capturePage" [@@bs.send];
    external make : id::float => session::Session.t => hostWebContents::WebContents.t => devToolsWebContents::WebContents.t => debugger::Debugger.t => t = "" [@@bs.obj];
    external setId : t => float => unit = "id" [@@bs.set];
    external getId : t => float = "id" [@@bs.get];

    external setSession : t => Session.t => unit = "session" [@@bs.set];
    external getSession : t => Session.t = "session" [@@bs.get];

    external setHostWebContents : t => WebContents.t => unit = "hostWebContents" [@@bs.set];
    external getHostWebContents : t => WebContents.t = "hostWebContents" [@@bs.get];

    external setDevToolsWebContents : t => WebContents.t => unit = "devToolsWebContents" [@@bs.set];
    external getDevToolsWebContents : t => WebContents.t = "devToolsWebContents" [@@bs.get];

    external setDebugger : t => Debugger.t => unit = "debugger" [@@bs.set];
    external getDebugger : t => Debugger.t = "debugger" [@@bs.get];

  };

  let module BeginFrameSubscriptionCallback = {
    type t;

    external invoke : t => Buffer.t => Rectangle.t? => unit => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module ContextMenuParams = {
    type t;

    let module MediaFlagsType = {
      type t;

      external make : inError::bool => isPaused::bool => isMuted::bool => hasAudio::bool => isLooping::bool => isControlsVisible::bool => canToggleControls::bool => canRotate::bool => t = "" [@@bs.obj];
      external setInError : t => bool => unit = "inError" [@@bs.set];
      external getInError : t => bool = "inError" [@@bs.get];

      external setIsPaused : t => bool => unit = "isPaused" [@@bs.set];
      external getIsPaused : t => bool = "isPaused" [@@bs.get];

      external setIsMuted : t => bool => unit = "isMuted" [@@bs.set];
      external getIsMuted : t => bool = "isMuted" [@@bs.get];

      external setHasAudio : t => bool => unit = "hasAudio" [@@bs.set];
      external getHasAudio : t => bool = "hasAudio" [@@bs.get];

      external setIsLooping : t => bool => unit = "isLooping" [@@bs.set];
      external getIsLooping : t => bool = "isLooping" [@@bs.get];

      external setIsControlsVisible : t => bool => unit = "isControlsVisible" [@@bs.set];
      external getIsControlsVisible : t => bool = "isControlsVisible" [@@bs.get];

      external setCanToggleControls : t => bool => unit = "canToggleControls" [@@bs.set];
      external getCanToggleControls : t => bool = "canToggleControls" [@@bs.get];

      external setCanRotate : t => bool => unit = "canRotate" [@@bs.set];
      external getCanRotate : t => bool = "canRotate" [@@bs.get];

    };

    let module EditFlagsType = {
      type t;

      external make : canUndo::bool => canRedo::bool => canCut::bool => canCopy::bool => canPaste::bool => canDelete::bool => canSelectAll::bool => t = "" [@@bs.obj];
      external setCanUndo : t => bool => unit = "canUndo" [@@bs.set];
      external getCanUndo : t => bool = "canUndo" [@@bs.get];

      external setCanRedo : t => bool => unit = "canRedo" [@@bs.set];
      external getCanRedo : t => bool = "canRedo" [@@bs.get];

      external setCanCut : t => bool => unit = "canCut" [@@bs.set];
      external getCanCut : t => bool = "canCut" [@@bs.get];

      external setCanCopy : t => bool => unit = "canCopy" [@@bs.set];
      external getCanCopy : t => bool = "canCopy" [@@bs.get];

      external setCanPaste : t => bool => unit = "canPaste" [@@bs.set];
      external getCanPaste : t => bool = "canPaste" [@@bs.get];

      external setCanDelete : t => bool => unit = "canDelete" [@@bs.set];
      external getCanDelete : t => bool = "canDelete" [@@bs.get];

      external setCanSelectAll : t => bool => unit = "canSelectAll" [@@bs.set];
      external getCanSelectAll : t => bool = "canSelectAll" [@@bs.get];

    };

    external make : x::float => y::float => linkURL::string => linkText::string => pageURL::string => frameURL::string => srcURL::string => mediaType::'a => mediaFlags::MediaFlagsType.t => hasImageContents::bool => isEditable::bool => editFlags::EditFlagsType.t => selectionText::string => titleText::string => misspelledWord::string => frameCharset::string => inputFieldType::'a => menuSourceType::'a => t = "" [@@bs.obj];
    external setX : t => float => unit = "x" [@@bs.set];
    external getX : t => float = "x" [@@bs.get];

    external setY : t => float => unit = "y" [@@bs.set];
    external getY : t => float = "y" [@@bs.get];

    external setLinkURL : t => string => unit = "linkURL" [@@bs.set];
    external getLinkURL : t => string = "linkURL" [@@bs.get];

    external setLinkText : t => string => unit = "linkText" [@@bs.set];
    external getLinkText : t => string = "linkText" [@@bs.get];

    external setPageURL : t => string => unit = "pageURL" [@@bs.set];
    external getPageURL : t => string = "pageURL" [@@bs.get];

    external setFrameURL : t => string => unit = "frameURL" [@@bs.set];
    external getFrameURL : t => string = "frameURL" [@@bs.get];

    external setSrcURL : t => string => unit = "srcURL" [@@bs.set];
    external getSrcURL : t => string = "srcURL" [@@bs.get];

    external setMediaType : t => 'a => unit = "mediaType" [@@bs.set];
    external getMediaType : t => 'a = "mediaType" [@@bs.get];

    external setMediaFlags : t => MediaFlagsType.t => unit = "mediaFlags" [@@bs.set];
    external getMediaFlags : t => MediaFlagsType.t = "mediaFlags" [@@bs.get];

    external setHasImageContents : t => bool => unit = "hasImageContents" [@@bs.set];
    external getHasImageContents : t => bool = "hasImageContents" [@@bs.get];

    external setIsEditable : t => bool => unit = "isEditable" [@@bs.set];
    external getIsEditable : t => bool = "isEditable" [@@bs.get];

    external setEditFlags : t => EditFlagsType.t => unit = "editFlags" [@@bs.set];
    external getEditFlags : t => EditFlagsType.t = "editFlags" [@@bs.get];

    external setSelectionText : t => string => unit = "selectionText" [@@bs.set];
    external getSelectionText : t => string = "selectionText" [@@bs.get];

    external setTitleText : t => string => unit = "titleText" [@@bs.set];
    external getTitleText : t => string = "titleText" [@@bs.get];

    external setMisspelledWord : t => string => unit = "misspelledWord" [@@bs.set];
    external getMisspelledWord : t => string = "misspelledWord" [@@bs.get];

    external setFrameCharset : t => string => unit = "frameCharset" [@@bs.set];
    external getFrameCharset : t => string = "frameCharset" [@@bs.get];

    external setInputFieldType : t => 'a => unit = "inputFieldType" [@@bs.set];
    external getInputFieldType : t => 'a = "inputFieldType" [@@bs.get];

    external setMenuSourceType : t => 'a => unit = "menuSourceType" [@@bs.set];
    external getMenuSourceType : t => 'a = "menuSourceType" [@@bs.get];

  };

  let module BluetoothDevice = {
    type t;

    external make : deviceName::string => deviceId::string => t = "" [@@bs.obj];
    external setDeviceName : t => string => unit = "deviceName" [@@bs.set];
    external getDeviceName : t => string = "deviceName" [@@bs.get];

    external setDeviceId : t => string => unit = "deviceId" [@@bs.set];
    external getDeviceId : t => string = "deviceId" [@@bs.get];

  };

  let module Headers = {
    type t;

    external value : t => string => string = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module NewWindowDisposition = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module StopFindInPageAtion = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module CursorType = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module LoadURLOptions = {
    type t;

    external make : httpReferrer::string? => userAgent::string? => extraHeaders::string? => postData::(array 'a)? => unit => t = "" [@@bs.obj];
    external setHttpReferrer : t => option string => unit = "httpReferrer" [@@bs.set];
    external getHttpReferrer : t => option string = "httpReferrer" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setUserAgent : t => option string => unit = "userAgent" [@@bs.set];
    external getUserAgent : t => option string = "userAgent" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setExtraHeaders : t => option string => unit = "extraHeaders" [@@bs.set];
    external getExtraHeaders : t => option string = "extraHeaders" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPostData : t => option (array 'a) => unit = "postData" [@@bs.set];
    external getPostData : t => option (array 'a) = "postData" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module UploadRawData = {
    type t;

    external make : type_::string => bytes::Buffer.t => t = "" [@@bs.obj];
    external setType : t => string => unit = "type" [@@bs.set];
    external getType : t => string = "type" [@@bs.get];

    external setBytes : t => Buffer.t => unit = "bytes" [@@bs.set];
    external getBytes : t => Buffer.t = "bytes" [@@bs.get];

  };

  let module UploadFileSystem = {
    type t;

    external make : type_::string => fileSystemURL::string => offset::float => length::float => modificationTime::float => t = "" [@@bs.obj];
    external setType : t => string => unit = "type" [@@bs.set];
    external getType : t => string = "type" [@@bs.get];

    external setFileSystemURL : t => string => unit = "fileSystemURL" [@@bs.set];
    external getFileSystemURL : t => string = "fileSystemURL" [@@bs.get];

    external setOffset : t => float => unit = "offset" [@@bs.set];
    external getOffset : t => float = "offset" [@@bs.get];

    external setLength : t => float => unit = "length" [@@bs.set];
    external getLength : t => float = "length" [@@bs.get];

    external setModificationTime : t => float => unit = "modificationTime" [@@bs.set];
    external getModificationTime : t => float = "modificationTime" [@@bs.get];

  };

  let module UploadBlob = {
    type t;

    external make : type_::string => blobUUID::string => t = "" [@@bs.obj];
    external setType : t => string => unit = "type" [@@bs.set];
    external getType : t => string = "type" [@@bs.get];

    external setBlobUUID : t => string => unit = "blobUUID" [@@bs.set];
    external getBlobUUID : t => string = "blobUUID" [@@bs.get];

  };

  let module PrintOptions = {
    type t;

    external make : silent::bool? => printBackground::bool? => unit => t = "" [@@bs.obj];
    external setSilent : t => option bool => unit = "silent" [@@bs.set];
    external getSilent : t => option bool = "silent" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPrintBackground : t => option bool => unit = "printBackground" [@@bs.set];
    external getPrintBackground : t => option bool = "printBackground" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module PrintToPDFOptions = {
    type t;

    external make : marginsType::float? => pageSize::'a? => printBackground::bool? => printSelectionOnly::bool? => landscape::bool? => unit => t = "" [@@bs.obj];
    external setMarginsType : t => option float => unit = "marginsType" [@@bs.set];
    external getMarginsType : t => option float = "marginsType" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPageSize : t => option 'a => unit = "pageSize" [@@bs.set];
    external getPageSize : t => option 'a = "pageSize" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPrintBackground : t => option bool => unit = "printBackground" [@@bs.set];
    external getPrintBackground : t => option bool = "printBackground" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setPrintSelectionOnly : t => option bool => unit = "printSelectionOnly" [@@bs.set];
    external getPrintSelectionOnly : t => option bool = "printSelectionOnly" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLandscape : t => option bool => unit = "landscape" [@@bs.set];
    external getLandscape : t => option bool = "landscape" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module Certificate = {
    type t;

    external make : data::string => issuer::CertificatePrincipal.t => issuerName::string => issuerCert::Certificate.t => subject::CertificatePrincipal.t => subjectName::string => serialNumber::string => validStart::float => validExpiry::float => fingerprint::string => t = "" [@@bs.obj];
    external setData : t => string => unit = "data" [@@bs.set];
    external getData : t => string = "data" [@@bs.get];

    external setIssuer : t => CertificatePrincipal.t => unit = "issuer" [@@bs.set];
    external getIssuer : t => CertificatePrincipal.t = "issuer" [@@bs.get];

    external setIssuerName : t => string => unit = "issuerName" [@@bs.set];
    external getIssuerName : t => string = "issuerName" [@@bs.get];

    external setIssuerCert : t => Certificate.t => unit = "issuerCert" [@@bs.set];
    external getIssuerCert : t => Certificate.t = "issuerCert" [@@bs.get];

    external setSubject : t => CertificatePrincipal.t => unit = "subject" [@@bs.set];
    external getSubject : t => CertificatePrincipal.t = "subject" [@@bs.get];

    external setSubjectName : t => string => unit = "subjectName" [@@bs.set];
    external getSubjectName : t => string = "subjectName" [@@bs.get];

    external setSerialNumber : t => string => unit = "serialNumber" [@@bs.set];
    external getSerialNumber : t => string = "serialNumber" [@@bs.get];

    external setValidStart : t => float => unit = "validStart" [@@bs.set];
    external getValidStart : t => float = "validStart" [@@bs.get];

    external setValidExpiry : t => float => unit = "validExpiry" [@@bs.set];
    external getValidExpiry : t => float = "validExpiry" [@@bs.get];

    external setFingerprint : t => string => unit = "fingerprint" [@@bs.set];
    external getFingerprint : t => string = "fingerprint" [@@bs.get];

  };

  let module CertificatePrincipal = {
    type t;

    external make : commonName::string => organizations::(array string) => organizationUnits::(array string) => locality::string => state::string => country::string => t = "" [@@bs.obj];
    external setCommonName : t => string => unit = "commonName" [@@bs.set];
    external getCommonName : t => string = "commonName" [@@bs.get];

    external setOrganizations : t => (array string) => unit = "organizations" [@@bs.set];
    external getOrganizations : t => (array string) = "organizations" [@@bs.get];

    external setOrganizationUnits : t => (array string) => unit = "organizationUnits" [@@bs.set];
    external getOrganizationUnits : t => (array string) = "organizationUnits" [@@bs.get];

    external setLocality : t => string => unit = "locality" [@@bs.set];
    external getLocality : t => string = "locality" [@@bs.get];

    external setState : t => string => unit = "state" [@@bs.set];
    external getState : t => string = "state" [@@bs.get];

    external setCountry : t => string => unit = "country" [@@bs.set];
    external getCountry : t => string = "country" [@@bs.get];

  };

  let module LoginRequest = {
    type t;

    external make : method::string => url::string => referrer::string => t = "" [@@bs.obj];
    external setMethod : t => string => unit = "method" [@@bs.set];
    external getMethod : t => string = "method" [@@bs.get];

    external setUrl : t => string => unit = "url" [@@bs.set];
    external getUrl : t => string = "url" [@@bs.get];

    external setReferrer : t => string => unit = "referrer" [@@bs.set];
    external getReferrer : t => string = "referrer" [@@bs.get];

  };

  let module LoginAuthInfo = {
    type t;

    external make : isProxy::bool => scheme::string => host::string => port::float => realm::string => t = "" [@@bs.obj];
    external setIsProxy : t => bool => unit = "isProxy" [@@bs.set];
    external getIsProxy : t => bool = "isProxy" [@@bs.get];

    external setScheme : t => string => unit = "scheme" [@@bs.set];
    external getScheme : t => string = "scheme" [@@bs.get];

    external setHost : t => string => unit = "host" [@@bs.set];
    external getHost : t => string = "host" [@@bs.get];

    external setPort : t => float => unit = "port" [@@bs.set];
    external getPort : t => float = "port" [@@bs.get];

    external setRealm : t => string => unit = "realm" [@@bs.set];
    external getRealm : t => string = "realm" [@@bs.get];

  };

  let module FindInPageOptions = {
    type t;

    external make : forward::bool? => findNext::bool? => matchCase::bool? => wordStart::bool? => medialCapitalAsWordStart::bool? => unit => t = "" [@@bs.obj];
    external setForward : t => option bool => unit = "forward" [@@bs.set];
    external getForward : t => option bool = "forward" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setFindNext : t => option bool => unit = "findNext" [@@bs.set];
    external getFindNext : t => option bool = "findNext" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMatchCase : t => option bool => unit = "matchCase" [@@bs.set];
    external getMatchCase : t => option bool = "matchCase" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWordStart : t => option bool => unit = "wordStart" [@@bs.set];
    external getWordStart : t => option bool = "wordStart" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMedialCapitalAsWordStart : t => option bool => unit = "medialCapitalAsWordStart" [@@bs.set];
    external getMedialCapitalAsWordStart : t => option bool = "medialCapitalAsWordStart" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module FoundInPageResult = {
    type t;

    external make : requestId::float => finalUpdate::bool => activeMatchOrdinal::float? => matches::float? => selectionArea::Rectangle.t? => unit => t = "" [@@bs.obj];
    external setRequestId : t => float => unit = "requestId" [@@bs.set];
    external getRequestId : t => float = "requestId" [@@bs.get];

    external setFinalUpdate : t => bool => unit = "finalUpdate" [@@bs.set];
    external getFinalUpdate : t => bool = "finalUpdate" [@@bs.get];

    external setActiveMatchOrdinal : t => option float => unit = "activeMatchOrdinal" [@@bs.set];
    external getActiveMatchOrdinal : t => option float = "activeMatchOrdinal" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMatches : t => option float => unit = "matches" [@@bs.set];
    external getMatches : t => option float = "matches" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSelectionArea : t => option Rectangle.t => unit = "selectionArea" [@@bs.set];
    external getSelectionArea : t => option Rectangle.t = "selectionArea" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module DeviceEmulationParameters = {
    type t;

    external make : screenPosition::'a? => screenSize::Size.t? => viewPosition::Point.t? => deviceScaleFactor::float => viewSize::Size.t? => fitToView::bool? => offset::Point.t? => scale::float => unit => t = "" [@@bs.obj];
    external setScreenPosition : t => option 'a => unit = "screenPosition" [@@bs.set];
    external getScreenPosition : t => option 'a = "screenPosition" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setScreenSize : t => option Size.t => unit = "screenSize" [@@bs.set];
    external getScreenSize : t => option Size.t = "screenSize" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setViewPosition : t => option Point.t => unit = "viewPosition" [@@bs.set];
    external getViewPosition : t => option Point.t = "viewPosition" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDeviceScaleFactor : t => float => unit = "deviceScaleFactor" [@@bs.set];
    external getDeviceScaleFactor : t => float = "deviceScaleFactor" [@@bs.get];

    external setViewSize : t => option Size.t => unit = "viewSize" [@@bs.set];
    external getViewSize : t => option Size.t = "viewSize" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setFitToView : t => option bool => unit = "fitToView" [@@bs.set];
    external getFitToView : t => option bool = "fitToView" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setOffset : t => option Point.t => unit = "offset" [@@bs.set];
    external getOffset : t => option Point.t = "offset" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setScale : t => float => unit = "scale" [@@bs.set];
    external getScale : t => float = "scale" [@@bs.get];

  };

  let module SendInputEvent = {
    type t;

    external make : type_::'a => modifiers::(array 'a) => t = "" [@@bs.obj];
    external setType : t => 'a => unit = "type" [@@bs.set];
    external getType : t => 'a = "type" [@@bs.get];

    external setModifiers : t => (array 'a) => unit = "modifiers" [@@bs.set];
    external getModifiers : t => (array 'a) = "modifiers" [@@bs.get];

  };

  let module SendInputKeyboardEvent = {
    type t;

    external make : keyCode::string => t = "" [@@bs.obj];
    external setKeyCode : t => string => unit = "keyCode" [@@bs.set];
    external getKeyCode : t => string = "keyCode" [@@bs.get];

  };

  let module SendInputMouseEvent = {
    type t;

    external make : x::float => y::float => button::'a? => globalX::float? => globalY::float? => movementX::float? => movementY::float? => clickCount::float? => unit => t = "" [@@bs.obj];
    external setX : t => float => unit = "x" [@@bs.set];
    external getX : t => float = "x" [@@bs.get];

    external setY : t => float => unit = "y" [@@bs.set];
    external getY : t => float = "y" [@@bs.get];

    external setButton : t => option 'a => unit = "button" [@@bs.set];
    external getButton : t => option 'a = "button" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setGlobalX : t => option float => unit = "globalX" [@@bs.set];
    external getGlobalX : t => option float = "globalX" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setGlobalY : t => option float => unit = "globalY" [@@bs.set];
    external getGlobalY : t => option float = "globalY" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMovementX : t => option float => unit = "movementX" [@@bs.set];
    external getMovementX : t => option float = "movementX" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMovementY : t => option float => unit = "movementY" [@@bs.set];
    external getMovementY : t => option float = "movementY" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setClickCount : t => option float => unit = "clickCount" [@@bs.set];
    external getClickCount : t => option float = "clickCount" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module SendInputMouseWheelEvent = {
    type t;

    external make : deltaX::float? => deltaY::float? => wheelTicksX::float? => wheelTicksY::float? => accelerationRatioX::float? => accelerationRatioY::float? => hasPreciseScrollingDeltas::bool? => canScroll::bool? => unit => t = "" [@@bs.obj];
    external setDeltaX : t => option float => unit = "deltaX" [@@bs.set];
    external getDeltaX : t => option float = "deltaX" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDeltaY : t => option float => unit = "deltaY" [@@bs.set];
    external getDeltaY : t => option float = "deltaY" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWheelTicksX : t => option float => unit = "wheelTicksX" [@@bs.set];
    external getWheelTicksX : t => option float = "wheelTicksX" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWheelTicksY : t => option float => unit = "wheelTicksY" [@@bs.set];
    external getWheelTicksY : t => option float = "wheelTicksY" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAccelerationRatioX : t => option float => unit = "accelerationRatioX" [@@bs.set];
    external getAccelerationRatioX : t => option float = "accelerationRatioX" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAccelerationRatioY : t => option float => unit = "accelerationRatioY" [@@bs.set];
    external getAccelerationRatioY : t => option float = "accelerationRatioY" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHasPreciseScrollingDeltas : t => option bool => unit = "hasPreciseScrollingDeltas" [@@bs.set];
    external getHasPreciseScrollingDeltas : t => option bool = "hasPreciseScrollingDeltas" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setCanScroll : t => option bool => unit = "canScroll" [@@bs.set];
    external getCanScroll : t => option bool = "canScroll" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module Debugger = {
    type t;

    external attach : t => string? => unit => unit = "" [@@bs.send];
    external isAttached : t => bool = "" [@@bs.send];
    external detach : t => unit = "" [@@bs.send];
    external sendCommand : t => string => 'a? => (Error.t => 'a => unit)? => unit => unit = "" [@@bs.send];
    external onDetach : t => (_ [@bs.as "detach"]) => (Event.t => string => unit) => t = "on" [@@bs.send];
    external onMessage : t => (_ [@bs.as "message"]) => (Event.t => string => 'a => unit) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module WebFrame = {
    type t;

    let module ProviderType = {
      type t;

      external make : spellCheck::(string => bool) => t = "" [@@bs.obj];
      external setSpellCheck : t => (string => bool) => unit = "spellCheck" [@@bs.set];
      external getSpellCheck : t => (string => bool) = "spellCheck" [@@bs.get];

    };

    external setZoomFactor : t => float => unit = "" [@@bs.send];
    external getZoomFactor : t => float = "" [@@bs.send];
    external setZoomLevel : t => float => unit = "" [@@bs.send];
    external getZoomLevel : t => float = "" [@@bs.send];
    external setVisualZoomLevelLimits : t => float => float => unit = "" [@@bs.send];
    external setLayoutZoomLevelLimits : t => float => float => unit = "" [@@bs.send];
    external setSpellCheckProvider : t => string => bool => ProviderType.t => unit = "" [@@bs.send];
    external registerURLSchemeAsSecure : t => string => unit = "" [@@bs.send];
    external registerURLSchemeAsBypassingCSP : t => string => unit = "" [@@bs.send];
    external registerURLSchemeAsPrivileged : t => string => RegisterURLSchemeOptions.t? => unit => unit = "" [@@bs.send];
    external insertText : t => string => unit = "" [@@bs.send];
    external executeJavaScript : t => string => bool? => ('a => unit)? => unit => Promise.t ('a) = "" [@@bs.send];
    external getResourceUsage : t => ResourceUsages.t = "" [@@bs.send];
    external clearCache : t => unit = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module ResourceUsages = {
    type t;

    external make : fonts::ResourceUsage.t => images::ResourceUsage.t => cssStyleSheets::ResourceUsage.t => xslStyleSheets::ResourceUsage.t => scripts::ResourceUsage.t => other::ResourceUsage.t => t = "" [@@bs.obj];
    external setFonts : t => ResourceUsage.t => unit = "fonts" [@@bs.set];
    external getFonts : t => ResourceUsage.t = "fonts" [@@bs.get];

    external setImages : t => ResourceUsage.t => unit = "images" [@@bs.set];
    external getImages : t => ResourceUsage.t = "images" [@@bs.get];

    external setCssStyleSheets : t => ResourceUsage.t => unit = "cssStyleSheets" [@@bs.set];
    external getCssStyleSheets : t => ResourceUsage.t = "cssStyleSheets" [@@bs.get];

    external setXslStyleSheets : t => ResourceUsage.t => unit = "xslStyleSheets" [@@bs.set];
    external getXslStyleSheets : t => ResourceUsage.t = "xslStyleSheets" [@@bs.get];

    external setScripts : t => ResourceUsage.t => unit = "scripts" [@@bs.set];
    external getScripts : t => ResourceUsage.t = "scripts" [@@bs.get];

    external setOther : t => ResourceUsage.t => unit = "other" [@@bs.set];
    external getOther : t => ResourceUsage.t = "other" [@@bs.get];

  };

  let module ResourceUsage = {
    type t;

    external make : count::float => decodedSize::float => liveSize::float => purgeableSize::float => purgedSize::float => size::float => t = "" [@@bs.obj];
    external setCount : t => float => unit = "count" [@@bs.set];
    external getCount : t => float = "count" [@@bs.get];

    external setDecodedSize : t => float => unit = "decodedSize" [@@bs.set];
    external getDecodedSize : t => float = "decodedSize" [@@bs.get];

    external setLiveSize : t => float => unit = "liveSize" [@@bs.set];
    external getLiveSize : t => float = "liveSize" [@@bs.get];

    external setPurgeableSize : t => float => unit = "purgeableSize" [@@bs.set];
    external getPurgeableSize : t => float = "purgeableSize" [@@bs.get];

    external setPurgedSize : t => float => unit = "purgedSize" [@@bs.set];
    external getPurgedSize : t => float = "purgedSize" [@@bs.get];

    external setSize : t => float => unit = "size" [@@bs.set];
    external getSize : t => float = "size" [@@bs.get];

  };

  let module RegisterURLSchemeOptions = {
    type t;

    external make : secure::bool? => bypassCSP::bool? => allowServiceWorkers::bool? => supportFetchAPI::bool? => corsEnabled::bool? => unit => t = "" [@@bs.obj];
    external setSecure : t => option bool => unit = "secure" [@@bs.set];
    external getSecure : t => option bool = "secure" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setBypassCSP : t => option bool => unit = "bypassCSP" [@@bs.set];
    external getBypassCSP : t => option bool = "bypassCSP" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setAllowServiceWorkers : t => option bool => unit = "allowServiceWorkers" [@@bs.set];
    external getAllowServiceWorkers : t => option bool = "allowServiceWorkers" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSupportFetchAPI : t => option bool => unit = "supportFetchAPI" [@@bs.set];
    external getSupportFetchAPI : t => option bool = "supportFetchAPI" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setCorsEnabled : t => option bool => unit = "corsEnabled" [@@bs.set];
    external getCorsEnabled : t => option bool = "corsEnabled" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module WebViewElement = {
    type t;

    external loadURL : t => string => LoadURLOptions.t? => unit => unit = "" [@@bs.send];
    external getURL : t => string = "" [@@bs.send];
    external getTitle : t => string = "" [@@bs.send];
    external isDestroyed : t => bool = "" [@@bs.send];
    external isFocused : t => bool = "" [@@bs.send];
    external isLoading : t => bool = "" [@@bs.send];
    external isWaitingForResponse : t => bool = "" [@@bs.send];
    external stop : t => unit = "" [@@bs.send];
    external reload : t => unit = "" [@@bs.send];
    external reloadIgnoringCache : t => unit = "" [@@bs.send];
    external canGoBack : t => bool = "" [@@bs.send];
    external canGoForward : t => bool = "" [@@bs.send];
    external canGoToOffset : t => float => bool = "" [@@bs.send];
    external clearHistory : t => unit = "" [@@bs.send];
    external goBack : t => unit = "" [@@bs.send];
    external goForward : t => unit = "" [@@bs.send];
    external goToIndex : t => float => unit = "" [@@bs.send];
    external goToOffset : t => float => unit = "" [@@bs.send];
    external isCrashed : t => bool = "" [@@bs.send];
    external setUserAgent : t => string => unit = "" [@@bs.send];
    external getUserAgent : t => string = "" [@@bs.send];
    external insertCSS : t => string => unit = "" [@@bs.send];
    external executeJavaScript : t => string => bool? => ('a => unit)? => unit => Promise.t ('a) = "" [@@bs.send];
    external openDevTools : t => unit = "" [@@bs.send];
    external closeDevTools : t => unit = "" [@@bs.send];
    external isDevToolsOpened : t => bool = "" [@@bs.send];
    external isDevToolsFocused : t => bool = "" [@@bs.send];
    external inspectElement : t => float => float => unit = "" [@@bs.send];
    external inspectServiceWorker : t => unit = "" [@@bs.send];
    external setAudioMuted : t => bool => unit = "" [@@bs.send];
    external isAudioMuted : t => bool = "" [@@bs.send];
    external undo : t => unit = "" [@@bs.send];
    external redo : t => unit = "" [@@bs.send];
    external cut : t => unit = "" [@@bs.send];
    external copy : t => unit = "" [@@bs.send];
    external paste : t => unit = "" [@@bs.send];
    external pasteAndMatchStyle : t => unit = "" [@@bs.send];
    external delete : t => unit = "" [@@bs.send];
    external selectAll : t => unit = "" [@@bs.send];
    external unselect : t => unit = "" [@@bs.send];
    external replace : t => string => unit = "" [@@bs.send];
    external replaceMisspelling : t => string => unit = "" [@@bs.send];
    external insertText : t => string => unit = "" [@@bs.send];
    external findInPage : t => string => FindInPageOptions.t? => unit => float = "" [@@bs.send];
    external stopFindInPage : t => StopFindInPageAtion.t => unit = "" [@@bs.send];
    external print : t => PrintOptions.t? => unit => unit = "" [@@bs.send];
    external printToPDF : t => PrintToPDFOptions.t => (Error.t => Buffer.t => unit) => unit = "" [@@bs.send];
    external send : t => string => (array 'a) => unit = "" [@@bs.send];
    external sendInputEvent : t => SendInputEvent.t => unit = "" [@@bs.send];
    external setZoomFactor : t => float => unit = "" [@@bs.send];
    external setZoomLevel : t => float => unit = "" [@@bs.send];
    external showDefinitionForSelection : t => unit = "" [@@bs.send];
    external getWebContents : t => WebContents.t = "" [@@bs.send];
    external capturePage0 : t => (NativeImage.t => unit) => unit = "capturePage" [@@bs.send];
    external capturePage1 : t => Rectangle.t => (NativeImage.t => unit) => unit = "capturePage" [@@bs.send];
    external addEventListenerLoadcommit : t => (_ [@bs.as "load-commit"]) => (WebViewElement.LoadCommitEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDidfinishload : t => (_ [@bs.as "did-finish-load"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDidfailload : t => (_ [@bs.as "did-fail-load"]) => (WebViewElement.DidFailLoadEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDidframefinishload : t => (_ [@bs.as "did-frame-finish-load"]) => (WebViewElement.DidFrameFinishLoadEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDidstartloading : t => (_ [@bs.as "did-start-loading"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDidstoploading : t => (_ [@bs.as "did-stop-loading"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDidgetresponsedetails : t => (_ [@bs.as "did-get-response-details"]) => (WebViewElement.DidGetResponseDetails.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDidgetredirectrequest : t => (_ [@bs.as "did-get-redirect-request"]) => (WebViewElement.DidGetRedirectRequestEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDomready : t => (_ [@bs.as "dom-ready"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerPagetitleupdated : t => (_ [@bs.as "page-title-updated"]) => (WebViewElement.PageTitleUpdatedEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerPagefaviconupdated : t => (_ [@bs.as "page-favicon-updated"]) => (WebViewElement.PageFaviconUpdatedEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerEnterhtmlfullscreen : t => (_ [@bs.as "enter-html-full-screen"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerLeavehtmlfullscreen : t => (_ [@bs.as "leave-html-full-screen"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerConsolemessage : t => (_ [@bs.as "console-message"]) => (WebViewElement.ConsoleMessageEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerFoundinpage : t => (_ [@bs.as "found-in-page"]) => (WebViewElement.FoundInPageEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerNewwindow : t => (_ [@bs.as "new-window"]) => (WebViewElement.NewWindowEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerWillnavigate : t => (_ [@bs.as "will-navigate"]) => (WebViewElement.WillNavigateEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDidnavigate : t => (_ [@bs.as "did-navigate"]) => (WebViewElement.DidNavigateEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDidnavigateinpage : t => (_ [@bs.as "did-navigate-in-page"]) => (WebViewElement.DidNavigateInPageEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerClose : t => (_ [@bs.as "close"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerIpcmessage : t => (_ [@bs.as "ipc-message"]) => (WebViewElement.IpcMessageEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerCrashed : t => (_ [@bs.as "crashed"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerGpucrashed : t => (_ [@bs.as "gpu-crashed"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerPlugincrashed : t => (_ [@bs.as "plugin-crashed"]) => (WebViewElement.PluginCrashedEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDestroyed : t => (_ [@bs.as "destroyed"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerMediastartedplaying : t => (_ [@bs.as "media-started-playing"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerMediapaused : t => (_ [@bs.as "media-paused"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDidchangethemecolor : t => (_ [@bs.as "did-change-theme-color"]) => (WebViewElement.DidChangeThemeColorEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerUpdatetargeturl : t => (_ [@bs.as "update-target-url"]) => (WebViewElement.UpdateTargetUrlEvent.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDevtoolsopened : t => (_ [@bs.as "devtools-opened"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDevtoolsclosed : t => (_ [@bs.as "devtools-closed"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListenerDevtoolsfocused : t => (_ [@bs.as "devtools-focused"]) => (WebViewElement.Event.t => unit) => bool? => unit => unit = "addEventListener" [@@bs.send];
    external addEventListener : t => string => (WebViewElement.Event.t => unit) => bool? => unit => unit = "" [@@bs.send];
    external make : src::string => autosize::string => nodeintegration::string => plugins::string => preload::string => httpreferrer::string => useragent::string => disablewebsecurity::string => partition::string => allowpopups::string => webpreferences::string => blinkfeatures::string => disableblinkfeatures::string => guestinstance::string => t = "" [@@bs.obj];
    external setSrc : t => string => unit = "src" [@@bs.set];
    external getSrc : t => string = "src" [@@bs.get];

    external setAutosize : t => string => unit = "autosize" [@@bs.set];
    external getAutosize : t => string = "autosize" [@@bs.get];

    external setNodeintegration : t => string => unit = "nodeintegration" [@@bs.set];
    external getNodeintegration : t => string = "nodeintegration" [@@bs.get];

    external setPlugins : t => string => unit = "plugins" [@@bs.set];
    external getPlugins : t => string = "plugins" [@@bs.get];

    external setPreload : t => string => unit = "preload" [@@bs.set];
    external getPreload : t => string = "preload" [@@bs.get];

    external setHttpreferrer : t => string => unit = "httpreferrer" [@@bs.set];
    external getHttpreferrer : t => string = "httpreferrer" [@@bs.get];

    external setUseragent : t => string => unit = "useragent" [@@bs.set];
    external getUseragent : t => string = "useragent" [@@bs.get];

    external setDisablewebsecurity : t => string => unit = "disablewebsecurity" [@@bs.set];
    external getDisablewebsecurity : t => string = "disablewebsecurity" [@@bs.get];

    external setPartition : t => string => unit = "partition" [@@bs.set];
    external getPartition : t => string = "partition" [@@bs.get];

    external setAllowpopups : t => string => unit = "allowpopups" [@@bs.set];
    external getAllowpopups : t => string = "allowpopups" [@@bs.get];

    external setWebpreferences : t => string => unit = "webpreferences" [@@bs.set];
    external getWebpreferences : t => string = "webpreferences" [@@bs.get];

    external setBlinkfeatures : t => string => unit = "blinkfeatures" [@@bs.set];
    external getBlinkfeatures : t => string = "blinkfeatures" [@@bs.get];

    external setDisableblinkfeatures : t => string => unit = "disableblinkfeatures" [@@bs.set];
    external getDisableblinkfeatures : t => string = "disableblinkfeatures" [@@bs.get];

    external setGuestinstance : t => string => unit = "guestinstance" [@@bs.set];
    external getGuestinstance : t => string = "guestinstance" [@@bs.get];

  };

  let module BrowserWindowProxy = {
    type t;

    external blur : t => unit = "" [@@bs.send];
    external close : t => unit = "" [@@bs.send];
    external eval : t => string => unit = "" [@@bs.send];
    external focus : t => unit = "" [@@bs.send];
    external postMessage : t => string => string => unit = "" [@@bs.send];
    external print : t => unit = "" [@@bs.send];
    external make : closed::bool => t = "" [@@bs.obj];
    external setClosed : t => bool => unit = "closed" [@@bs.set];
    external getClosed : t => bool = "closed" [@@bs.get];

  };

  let module CommonElectron = {
    type t;

    external make : clipboard::Electron.Clipboard.t => crashReporter::Electron.CrashReporter.t => nativeImage::'a => shell::Electron.Shell.t => app::Electron.App.t => autoUpdater::Electron.AutoUpdater.t => BrowserWindow::'a => contentTracing::Electron.ContentTracing.t => dialog::Electron.Dialog.t => ipcMain::Electron.IpcMain.t => globalShortcut::Electron.GlobalShortcut.t => Menu::'a => MenuItem::'a => net::Electron.Net.t => powerMonitor::Electron.PowerMonitor.t => powerSaveBlocker::Electron.PowerSaveBlocker.t => protocol::Electron.Protocol.t => screen::Electron.Screen.t => session::'a => systemPreferences::Electron.SystemPreferences.t => Tray::'a => webContents::Electron.WebContentsStatic.t => t = "" [@@bs.obj];
    external setClipboard : t => Electron.Clipboard.t => unit = "clipboard" [@@bs.set];
    external getClipboard : t => Electron.Clipboard.t = "clipboard" [@@bs.get];

    external setCrashReporter : t => Electron.CrashReporter.t => unit = "crashReporter" [@@bs.set];
    external getCrashReporter : t => Electron.CrashReporter.t = "crashReporter" [@@bs.get];

    external setNativeImage : t => 'a => unit = "nativeImage" [@@bs.set];
    external getNativeImage : t => 'a = "nativeImage" [@@bs.get];

    external setShell : t => Electron.Shell.t => unit = "shell" [@@bs.set];
    external getShell : t => Electron.Shell.t = "shell" [@@bs.get];

    external setApp : t => Electron.App.t => unit = "app" [@@bs.set];
    external getApp : t => Electron.App.t = "app" [@@bs.get];

    external setAutoUpdater : t => Electron.AutoUpdater.t => unit = "autoUpdater" [@@bs.set];
    external getAutoUpdater : t => Electron.AutoUpdater.t = "autoUpdater" [@@bs.get];

    external setBrowserWindow : t => 'a => unit = "BrowserWindow" [@@bs.set];
    external getBrowserWindow : t => 'a = "BrowserWindow" [@@bs.get];

    external setContentTracing : t => Electron.ContentTracing.t => unit = "contentTracing" [@@bs.set];
    external getContentTracing : t => Electron.ContentTracing.t = "contentTracing" [@@bs.get];

    external setDialog : t => Electron.Dialog.t => unit = "dialog" [@@bs.set];
    external getDialog : t => Electron.Dialog.t = "dialog" [@@bs.get];

    external setIpcMain : t => Electron.IpcMain.t => unit = "ipcMain" [@@bs.set];
    external getIpcMain : t => Electron.IpcMain.t = "ipcMain" [@@bs.get];

    external setGlobalShortcut : t => Electron.GlobalShortcut.t => unit = "globalShortcut" [@@bs.set];
    external getGlobalShortcut : t => Electron.GlobalShortcut.t = "globalShortcut" [@@bs.get];

    external setMenu : t => 'a => unit = "Menu" [@@bs.set];
    external getMenu : t => 'a = "Menu" [@@bs.get];

    external setMenuItem : t => 'a => unit = "MenuItem" [@@bs.set];
    external getMenuItem : t => 'a = "MenuItem" [@@bs.get];

    external setNet : t => Electron.Net.t => unit = "net" [@@bs.set];
    external getNet : t => Electron.Net.t = "net" [@@bs.get];

    external setPowerMonitor : t => Electron.PowerMonitor.t => unit = "powerMonitor" [@@bs.set];
    external getPowerMonitor : t => Electron.PowerMonitor.t = "powerMonitor" [@@bs.get];

    external setPowerSaveBlocker : t => Electron.PowerSaveBlocker.t => unit = "powerSaveBlocker" [@@bs.set];
    external getPowerSaveBlocker : t => Electron.PowerSaveBlocker.t = "powerSaveBlocker" [@@bs.get];

    external setProtocol : t => Electron.Protocol.t => unit = "protocol" [@@bs.set];
    external getProtocol : t => Electron.Protocol.t = "protocol" [@@bs.get];

    external setScreen : t => Electron.Screen.t => unit = "screen" [@@bs.set];
    external getScreen : t => Electron.Screen.t = "screen" [@@bs.get];

    external setSession : t => 'a => unit = "session" [@@bs.set];
    external getSession : t => 'a = "session" [@@bs.get];

    external setSystemPreferences : t => Electron.SystemPreferences.t => unit = "systemPreferences" [@@bs.set];
    external getSystemPreferences : t => Electron.SystemPreferences.t = "systemPreferences" [@@bs.get];

    external setTray : t => 'a => unit = "Tray" [@@bs.set];
    external getTray : t => 'a = "Tray" [@@bs.get];

    external setWebContents : t => Electron.WebContentsStatic.t => unit = "webContents" [@@bs.set];
    external getWebContents : t => Electron.WebContentsStatic.t = "webContents" [@@bs.get];

  };

  let module ElectronMainAndRenderer = {
    type t;

    external make : desktopCapturer::Electron.DesktopCapturer.t => ipcRenderer::Electron.IpcRenderer.t => remote::Electron.Remote.t => webFrame::Electron.WebFrame.t => t = "" [@@bs.obj];
    external setDesktopCapturer : t => Electron.DesktopCapturer.t => unit = "desktopCapturer" [@@bs.set];
    external getDesktopCapturer : t => Electron.DesktopCapturer.t = "desktopCapturer" [@@bs.get];

    external setIpcRenderer : t => Electron.IpcRenderer.t => unit = "ipcRenderer" [@@bs.set];
    external getIpcRenderer : t => Electron.IpcRenderer.t = "ipcRenderer" [@@bs.get];

    external setRemote : t => Electron.Remote.t => unit = "remote" [@@bs.set];
    external getRemote : t => Electron.Remote.t = "remote" [@@bs.get];

    external setWebFrame : t => Electron.WebFrame.t => unit = "webFrame" [@@bs.set];
    external getWebFrame : t => Electron.WebFrame.t = "webFrame" [@@bs.get];

  };

  let module WebRequest = {

    let module Filter = {
      type t;

      external make : urls::(array string) => t = "" [@@bs.obj];
      external setUrls : t => (array string) => unit = "urls" [@@bs.set];
      external getUrls : t => (array string) = "urls" [@@bs.get];

    };

    let module Details = {
      type t;

      external make : id::float => url::string => method::string => resourceType::string => timestamp::float => t = "" [@@bs.obj];
      external setId : t => float => unit = "id" [@@bs.set];
      external getId : t => float = "id" [@@bs.get];

      external setUrl : t => string => unit = "url" [@@bs.set];
      external getUrl : t => string = "url" [@@bs.get];

      external setMethod : t => string => unit = "method" [@@bs.set];
      external getMethod : t => string = "method" [@@bs.get];

      external setResourceType : t => string => unit = "resourceType" [@@bs.set];
      external getResourceType : t => string = "resourceType" [@@bs.get];

      external setTimestamp : t => float => unit = "timestamp" [@@bs.set];
      external getTimestamp : t => float = "timestamp" [@@bs.get];

    };

    let module UploadData = {
      type t;

      external make : bytes::Buffer.t => file::string => blobUUID::string => t = "" [@@bs.obj];
      external setBytes : t => Buffer.t => unit = "bytes" [@@bs.set];
      external getBytes : t => Buffer.t = "bytes" [@@bs.get];

      external setFile : t => string => unit = "file" [@@bs.set];
      external getFile : t => string = "file" [@@bs.get];

      external setBlobUUID : t => string => unit = "blobUUID" [@@bs.set];
      external getBlobUUID : t => string = "blobUUID" [@@bs.get];

    };

    let module BeforeRequestDetails = {
      type t;

      external make : uploadData::(array UploadData.t)? => unit => t = "" [@@bs.obj];
      external setUploadData : t => option (array UploadData.t) => unit = "uploadData" [@@bs.set];
      external getUploadData : t => option (array UploadData.t) = "uploadData" [@@bs.get] [@@bs.return null_undefined_to_opt];

    };

    let module BeforeRequestCallback = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module BeforeSendHeadersDetails = {
      type t;

      external make : requestHeaders::Headers.t => t = "" [@@bs.obj];
      external setRequestHeaders : t => Headers.t => unit = "requestHeaders" [@@bs.set];
      external getRequestHeaders : t => Headers.t = "requestHeaders" [@@bs.get];

    };

    let module BeforeSendHeadersCallback = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module SendHeadersDetails = {
      type t;

      external make : requestHeaders::Headers.t => t = "" [@@bs.obj];
      external setRequestHeaders : t => Headers.t => unit = "requestHeaders" [@@bs.set];
      external getRequestHeaders : t => Headers.t = "requestHeaders" [@@bs.get];

    };

    let module HeadersReceivedDetails = {
      type t;

      external make : statusLine::string => statusCode::float => responseHeaders::Headers.t => t = "" [@@bs.obj];
      external setStatusLine : t => string => unit = "statusLine" [@@bs.set];
      external getStatusLine : t => string = "statusLine" [@@bs.get];

      external setStatusCode : t => float => unit = "statusCode" [@@bs.set];
      external getStatusCode : t => float = "statusCode" [@@bs.get];

      external setResponseHeaders : t => Headers.t => unit = "responseHeaders" [@@bs.set];
      external getResponseHeaders : t => Headers.t = "responseHeaders" [@@bs.get];

    };

    let module HeadersReceivedCallback = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module ResponseStartedDetails = {
      type t;

      external make : responseHeaders::Headers.t => fromCache::bool => statusCode::float => statusLine::string => t = "" [@@bs.obj];
      external setResponseHeaders : t => Headers.t => unit = "responseHeaders" [@@bs.set];
      external getResponseHeaders : t => Headers.t = "responseHeaders" [@@bs.get];

      external setFromCache : t => bool => unit = "fromCache" [@@bs.set];
      external getFromCache : t => bool = "fromCache" [@@bs.get];

      external setStatusCode : t => float => unit = "statusCode" [@@bs.set];
      external getStatusCode : t => float = "statusCode" [@@bs.get];

      external setStatusLine : t => string => unit = "statusLine" [@@bs.set];
      external getStatusLine : t => string = "statusLine" [@@bs.get];

    };

    let module BeforeRedirectDetails = {
      type t;

      external make : redirectURL::string => statusCode::float => ip::string? => fromCache::bool => responseHeaders::Headers.t => unit => t = "" [@@bs.obj];
      external setRedirectURL : t => string => unit = "redirectURL" [@@bs.set];
      external getRedirectURL : t => string = "redirectURL" [@@bs.get];

      external setStatusCode : t => float => unit = "statusCode" [@@bs.set];
      external getStatusCode : t => float = "statusCode" [@@bs.get];

      external setIp : t => option string => unit = "ip" [@@bs.set];
      external getIp : t => option string = "ip" [@@bs.get] [@@bs.return null_undefined_to_opt];

      external setFromCache : t => bool => unit = "fromCache" [@@bs.set];
      external getFromCache : t => bool = "fromCache" [@@bs.get];

      external setResponseHeaders : t => Headers.t => unit = "responseHeaders" [@@bs.set];
      external getResponseHeaders : t => Headers.t = "responseHeaders" [@@bs.get];

    };

    let module CompletedDetails = {
      type t;

      external make : responseHeaders::Headers.t => fromCache::bool => statusCode::float => statusLine::string => t = "" [@@bs.obj];
      external setResponseHeaders : t => Headers.t => unit = "responseHeaders" [@@bs.set];
      external getResponseHeaders : t => Headers.t = "responseHeaders" [@@bs.get];

      external setFromCache : t => bool => unit = "fromCache" [@@bs.set];
      external getFromCache : t => bool = "fromCache" [@@bs.get];

      external setStatusCode : t => float => unit = "statusCode" [@@bs.set];
      external getStatusCode : t => float = "statusCode" [@@bs.get];

      external setStatusLine : t => string => unit = "statusLine" [@@bs.set];
      external getStatusLine : t => string = "statusLine" [@@bs.get];

    };

    let module ErrorOccurredDetails = {
      type t;

      external make : fromCache::bool => error::string => t = "" [@@bs.obj];
      external setFromCache : t => bool => unit = "fromCache" [@@bs.set];
      external getFromCache : t => bool = "fromCache" [@@bs.get];

      external setError : t => string => unit = "error" [@@bs.set];
      external getError : t => string = "error" [@@bs.get];

    };

  };

  let module WebViewElement = {

    let module Event = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module LoadCommitEvent = {
      type t;

      external make : url::string => isMainFrame::bool => t = "" [@@bs.obj];
      external setUrl : t => string => unit = "url" [@@bs.set];
      external getUrl : t => string = "url" [@@bs.get];

      external setIsMainFrame : t => bool => unit = "isMainFrame" [@@bs.set];
      external getIsMainFrame : t => bool = "isMainFrame" [@@bs.get];

    };

    let module DidFailLoadEvent = {
      type t;

      external make : errorCode::float => errorDescription::string => validatedURL::string => isMainFrame::bool => t = "" [@@bs.obj];
      external setErrorCode : t => float => unit = "errorCode" [@@bs.set];
      external getErrorCode : t => float = "errorCode" [@@bs.get];

      external setErrorDescription : t => string => unit = "errorDescription" [@@bs.set];
      external getErrorDescription : t => string = "errorDescription" [@@bs.get];

      external setValidatedURL : t => string => unit = "validatedURL" [@@bs.set];
      external getValidatedURL : t => string = "validatedURL" [@@bs.get];

      external setIsMainFrame : t => bool => unit = "isMainFrame" [@@bs.set];
      external getIsMainFrame : t => bool = "isMainFrame" [@@bs.get];

    };

    let module DidFrameFinishLoadEvent = {
      type t;

      external make : isMainFrame::bool => t = "" [@@bs.obj];
      external setIsMainFrame : t => bool => unit = "isMainFrame" [@@bs.set];
      external getIsMainFrame : t => bool = "isMainFrame" [@@bs.get];

    };

    let module DidGetResponseDetails = {
      type t;

      external make : status::bool => newURL::string => originalURL::string => httpResponseCode::float => requestMethod::string => referrer::string => headers::Headers.t => resourceType::string => t = "" [@@bs.obj];
      external setStatus : t => bool => unit = "status" [@@bs.set];
      external getStatus : t => bool = "status" [@@bs.get];

      external setNewURL : t => string => unit = "newURL" [@@bs.set];
      external getNewURL : t => string = "newURL" [@@bs.get];

      external setOriginalURL : t => string => unit = "originalURL" [@@bs.set];
      external getOriginalURL : t => string = "originalURL" [@@bs.get];

      external setHttpResponseCode : t => float => unit = "httpResponseCode" [@@bs.set];
      external getHttpResponseCode : t => float = "httpResponseCode" [@@bs.get];

      external setRequestMethod : t => string => unit = "requestMethod" [@@bs.set];
      external getRequestMethod : t => string = "requestMethod" [@@bs.get];

      external setReferrer : t => string => unit = "referrer" [@@bs.set];
      external getReferrer : t => string = "referrer" [@@bs.get];

      external setHeaders : t => Headers.t => unit = "headers" [@@bs.set];
      external getHeaders : t => Headers.t = "headers" [@@bs.get];

      external setResourceType : t => string => unit = "resourceType" [@@bs.set];
      external getResourceType : t => string = "resourceType" [@@bs.get];

    };

    let module DidGetRedirectRequestEvent = {
      type t;

      external make : oldURL::string => newURL::string => isMainFrame::bool => httpResponseCode::float => requestMethod::string => referrer::string => headers::Headers.t => t = "" [@@bs.obj];
      external setOldURL : t => string => unit = "oldURL" [@@bs.set];
      external getOldURL : t => string = "oldURL" [@@bs.get];

      external setNewURL : t => string => unit = "newURL" [@@bs.set];
      external getNewURL : t => string = "newURL" [@@bs.get];

      external setIsMainFrame : t => bool => unit = "isMainFrame" [@@bs.set];
      external getIsMainFrame : t => bool = "isMainFrame" [@@bs.get];

      external setHttpResponseCode : t => float => unit = "httpResponseCode" [@@bs.set];
      external getHttpResponseCode : t => float = "httpResponseCode" [@@bs.get];

      external setRequestMethod : t => string => unit = "requestMethod" [@@bs.set];
      external getRequestMethod : t => string = "requestMethod" [@@bs.get];

      external setReferrer : t => string => unit = "referrer" [@@bs.set];
      external getReferrer : t => string = "referrer" [@@bs.get];

      external setHeaders : t => Headers.t => unit = "headers" [@@bs.set];
      external getHeaders : t => Headers.t = "headers" [@@bs.get];

    };

    let module PageTitleUpdatedEvent = {
      type t;

      external make : title::string => explicitSet::string => t = "" [@@bs.obj];
      external setTitle : t => string => unit = "title" [@@bs.set];
      external getTitle : t => string = "title" [@@bs.get];

      external setExplicitSet : t => string => unit = "explicitSet" [@@bs.set];
      external getExplicitSet : t => string = "explicitSet" [@@bs.get];

    };

    let module PageFaviconUpdatedEvent = {
      type t;

      external make : favicons::(array string) => t = "" [@@bs.obj];
      external setFavicons : t => (array string) => unit = "favicons" [@@bs.set];
      external getFavicons : t => (array string) = "favicons" [@@bs.get];

    };

    let module ConsoleMessageEvent = {
      type t;

      external make : level::float => message::string => line::float => sourceId::string => t = "" [@@bs.obj];
      external setLevel : t => float => unit = "level" [@@bs.set];
      external getLevel : t => float = "level" [@@bs.get];

      external setMessage : t => string => unit = "message" [@@bs.set];
      external getMessage : t => string = "message" [@@bs.get];

      external setLine : t => float => unit = "line" [@@bs.set];
      external getLine : t => float = "line" [@@bs.get];

      external setSourceId : t => string => unit = "sourceId" [@@bs.set];
      external getSourceId : t => string = "sourceId" [@@bs.get];

    };

    let module FoundInPageEvent = {
      type t;

      external make : result::FoundInPageResult.t => t = "" [@@bs.obj];
      external setResult : t => FoundInPageResult.t => unit = "result" [@@bs.set];
      external getResult : t => FoundInPageResult.t = "result" [@@bs.get];

    };

    let module NewWindowEvent = {
      type t;

      external make : url::string => frameName::string => disposition::NewWindowDisposition.t => options::BrowserWindowOptions.t => t = "" [@@bs.obj];
      external setUrl : t => string => unit = "url" [@@bs.set];
      external getUrl : t => string = "url" [@@bs.get];

      external setFrameName : t => string => unit = "frameName" [@@bs.set];
      external getFrameName : t => string = "frameName" [@@bs.get];

      external setDisposition : t => NewWindowDisposition.t => unit = "disposition" [@@bs.set];
      external getDisposition : t => NewWindowDisposition.t = "disposition" [@@bs.get];

      external setOptions : t => BrowserWindowOptions.t => unit = "options" [@@bs.set];
      external getOptions : t => BrowserWindowOptions.t = "options" [@@bs.get];

    };

    let module WillNavigateEvent = {
      type t;

      external make : url::string => t = "" [@@bs.obj];
      external setUrl : t => string => unit = "url" [@@bs.set];
      external getUrl : t => string = "url" [@@bs.get];

    };

    let module DidNavigateEvent = {
      type t;

      external make : url::string => t = "" [@@bs.obj];
      external setUrl : t => string => unit = "url" [@@bs.set];
      external getUrl : t => string = "url" [@@bs.get];

    };

    let module DidNavigateInPageEvent = {
      type t;

      external make : url::string => isMainFrame::bool => t = "" [@@bs.obj];
      external setUrl : t => string => unit = "url" [@@bs.set];
      external getUrl : t => string = "url" [@@bs.get];

      external setIsMainFrame : t => bool => unit = "isMainFrame" [@@bs.set];
      external getIsMainFrame : t => bool = "isMainFrame" [@@bs.get];

    };

    let module IpcMessageEvent = {
      type t;

      external make : channel::string => args::(array 'a) => t = "" [@@bs.obj];
      external setChannel : t => string => unit = "channel" [@@bs.set];
      external getChannel : t => string = "channel" [@@bs.get];

      external setArgs : t => (array 'a) => unit = "args" [@@bs.set];
      external getArgs : t => (array 'a) = "args" [@@bs.get];

    };

    let module PluginCrashedEvent = {
      type t;

      external make : name::string => version::string => t = "" [@@bs.obj];
      external setName : t => string => unit = "name" [@@bs.set];
      external getName : t => string = "name" [@@bs.get];

      external setVersion : t => string => unit = "version" [@@bs.set];
      external getVersion : t => string = "version" [@@bs.get];

    };

    let module DidChangeThemeColorEvent = {
      type t;

      external make : themeColor::string => t = "" [@@bs.obj];
      external setThemeColor : t => string => unit = "themeColor" [@@bs.set];
      external getThemeColor : t => string = "themeColor" [@@bs.get];

    };

    let module UpdateTargetUrlEvent = {
      type t;

      external make : url::string => t = "" [@@bs.obj];
      external setUrl : t => string => unit = "url" [@@bs.set];
      external getUrl : t => string = "url" [@@bs.get];

    };

  };

};

let module ElectronPrivate = {

  let module GlobalEvent = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

};

let module NodeJS = {

  let module ProcessVersions = {
    type t;

    external make : electron::string => chrome::string => t = "" [@@bs.obj];
    external setElectron : t => string => unit = "electron" [@@bs.set];
    external getElectron : t => string = "electron" [@@bs.get];

    external setChrome : t => string => unit = "chrome" [@@bs.set];
    external getChrome : t => string = "chrome" [@@bs.get];

  };

  let module Process = {
    type t;

    external onLoaded : t => (_ [@bs.as "loaded"]) => ('x => 'y) => t = "on" [@@bs.send];
    external on : t => string => ('x => 'y) => t = "" [@@bs.send];
    external crash : t => unit = "" [@@bs.send];
    external hang : t => unit = "" [@@bs.send];
    external setFdLimit : t => float => unit = "" [@@bs.send];
    external getProcessMemoryInfo : t => ProcessMemoryInfo.t = "" [@@bs.send];
    external getSystemMemoryInfo : t => SystemMemoryInfo.t = "" [@@bs.send];
    external make : noAsar::bool? => type_::'a => resourcesPath::string => mas::bool? => windowsStore::bool? => defaultApp::bool? => unit => t = "" [@@bs.obj];
    external setNoAsar : t => option bool => unit = "noAsar" [@@bs.set];
    external getNoAsar : t => option bool = "noAsar" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setType : t => 'a => unit = "type" [@@bs.set];
    external getType : t => 'a = "type" [@@bs.get];

    external setResourcesPath : t => string => unit = "resourcesPath" [@@bs.set];
    external getResourcesPath : t => string = "resourcesPath" [@@bs.get];

    external setMas : t => option bool => unit = "mas" [@@bs.set];
    external getMas : t => option bool = "mas" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWindowsStore : t => option bool => unit = "windowsStore" [@@bs.set];
    external getWindowsStore : t => option bool = "windowsStore" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDefaultApp : t => option bool => unit = "defaultApp" [@@bs.set];
    external getDefaultApp : t => option bool = "defaultApp" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module ProcessMemoryInfo = {
    type t;

    external make : workingSetSize::float => peakWorkingSetSize::float => privateBytes::float => sharedBytes::float => t = "" [@@bs.obj];
    external setWorkingSetSize : t => float => unit = "workingSetSize" [@@bs.set];
    external getWorkingSetSize : t => float = "workingSetSize" [@@bs.get];

    external setPeakWorkingSetSize : t => float => unit = "peakWorkingSetSize" [@@bs.set];
    external getPeakWorkingSetSize : t => float = "peakWorkingSetSize" [@@bs.get];

    external setPrivateBytes : t => float => unit = "privateBytes" [@@bs.set];
    external getPrivateBytes : t => float = "privateBytes" [@@bs.get];

    external setSharedBytes : t => float => unit = "sharedBytes" [@@bs.set];
    external getSharedBytes : t => float = "sharedBytes" [@@bs.get];

  };

  let module SystemMemoryInfo = {
    type t;

    external make : total::float => free::float => swapTotal::float => swapFree::float => t = "" [@@bs.obj];
    external setTotal : t => float => unit = "total" [@@bs.set];
    external getTotal : t => float = "total" [@@bs.get];

    external setFree : t => float => unit = "free" [@@bs.set];
    external getFree : t => float = "free" [@@bs.get];

    external setSwapTotal : t => float => unit = "swapTotal" [@@bs.set];
    external getSwapTotal : t => float = "swapTotal" [@@bs.get];

    external setSwapFree : t => float => unit = "swapFree" [@@bs.set];
    external getSwapFree : t => float = "swapFree" [@@bs.get];

  };

};

let module Electron = {

};

