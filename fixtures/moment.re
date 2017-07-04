external moment :  => moment.MomentInput.t? => moment.MomentFormatSpecification.t? => bool? => (unit [@bs.ignore]) => moment.Moment.t = "";
external moment :  => moment.MomentInput.t? => moment.MomentFormatSpecification.t? => string? => bool? => (unit [@bs.ignore]) => moment.Moment.t = "";
let module Moment = {

  external utc :  => MomentInput.t? => MomentFormatSpecification.t? => bool? => (unit [@bs.ignore]) => Moment.t = "";
  external utc :  => MomentInput.t? => MomentFormatSpecification.t? => string? => bool? => (unit [@bs.ignore]) => Moment.t = "";
  external unix :  => float => Moment.t = "";
  external invalid :  => MomentParsingFlagsOpt.t? => (unit [@bs.ignore]) => Moment.t = "";
  external isMoment :  => 'Any => 'UnknownType = "";
  external isDate :  => 'Any => 'UnknownType = "";
  external isDuration :  => 'Any => 'UnknownType = "";
  external lang :  => string? => (unit [@bs.ignore]) => string = "";
  external lang :  => string? => Locale.t? => (unit [@bs.ignore]) => string = "";
  external locale :  => string? => (unit [@bs.ignore]) => string = "";
  external locale :  => (array string)? => (unit [@bs.ignore]) => string = "";
  external locale :  => string? => (definitionType 'a [@bs.ignore]) => 'a? => (unit [@bs.ignore]) => string = "";
  external localeData :  => (keyType 'a [@bs.ignore]) => 'a? => (unit [@bs.ignore]) => Locale.t = "";
  external duration :  => DurationInputArg1.t? => DurationInputArg2.t? => (unit [@bs.ignore]) => Duration.t = "";
  external parseZone :  => MomentInput.t? => MomentFormatSpecification.t? => bool? => (unit [@bs.ignore]) => Moment.t = "";
  external parseZone :  => MomentInput.t? => MomentFormatSpecification.t? => string? => bool? => (unit [@bs.ignore]) => Moment.t = "";
  external months : unit => (array string) = "";
  external months :  => float => string = "";
  external months :  => string => (array string) = "";
  external months :  => string => float => string = "";
  external monthsShort : unit => (array string) = "";
  external monthsShort :  => float => string = "";
  external monthsShort :  => string => (array string) = "";
  external monthsShort :  => string => float => string = "";
  external weekdays : unit => (array string) = "";
  external weekdays :  => float => string = "";
  external weekdays :  => string => (array string) = "";
  external weekdays :  => string => float => string = "";
  external weekdays :  => bool => (array string) = "";
  external weekdays :  => bool => float => string = "";
  external weekdays :  => bool => string => (array string) = "";
  external weekdays :  => bool => string => float => string = "";
  external weekdaysShort : unit => (array string) = "";
  external weekdaysShort :  => float => string = "";
  external weekdaysShort :  => string => (array string) = "";
  external weekdaysShort :  => string => float => string = "";
  external weekdaysShort :  => bool => (array string) = "";
  external weekdaysShort :  => bool => float => string = "";
  external weekdaysShort :  => bool => string => (array string) = "";
  external weekdaysShort :  => bool => string => float => string = "";
  external weekdaysMin : unit => (array string) = "";
  external weekdaysMin :  => float => string = "";
  external weekdaysMin :  => string => (array string) = "";
  external weekdaysMin :  => string => float => string = "";
  external weekdaysMin :  => bool => (array string) = "";
  external weekdaysMin :  => bool => float => string = "";
  external weekdaysMin :  => bool => string => (array string) = "";
  external weekdaysMin :  => bool => string => float => string = "";
  external min :  => (array MomentInput.t) => Moment.t = "";
  external max :  => (array MomentInput.t) => Moment.t = "";
  external now : unit => float = "";
  external defineLocale :  => string => (localeSpecType 'a [@bs.ignore]) => 'a => Locale.t = "";
  external updateLocale :  => string => (localeSpecType 'a [@bs.ignore]) => 'a => Locale.t = "";
  external locales : unit => (array string) = "";
  external normalizeUnits :  => unitOfTime.All.t => string = "";
  external relativeTimeThreshold :  => string => relativeTimeThresholdType = "";
  external relativeTimeThreshold :  => string => float => bool = "";
  external relativeTimeRounding :  => (float => float) => bool = "";
  external relativeTimeRounding : unit => (float => float) = "";
  external calendarFormat :  => Moment.t => Moment.t => string = "";
  let module RelativeTimeKey = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module CalendarKey = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module LongDateFormatKey = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module Locale = {
    type t;

    external calendar : t => CalendarKey.t? => Moment.t? => Moment.t? => (unit [@bs.ignore]) => string = "" [@@bs.send];
    external longDateFormat : t => LongDateFormatKey.t => string = "" [@@bs.send];
    external invalidDate : t => string = "" [@@bs.send];
    external ordinal : t => float => string = "" [@@bs.send];
    external preparse : t => string => string = "" [@@bs.send];
    external postformat : t => string => string = "" [@@bs.send];
    external relativeTime : t => float => bool => RelativeTimeKey.t => bool => string = "" [@@bs.send];
    external pastFuture : t => float => string => string = "" [@@bs.send];
    external set : t => Object.t => unit = "" [@@bs.send];
    external months0 : t => (array string) = "months" [@@bs.send];
    external months1 : t => Moment.t => string? => (unit [@bs.ignore]) => string = "months" [@@bs.send];
    external monthsShort0 : t => (array string) = "monthsShort" [@@bs.send];
    external monthsShort1 : t => Moment.t => string? => (unit [@bs.ignore]) => string = "monthsShort" [@@bs.send];
    external monthsParse : t => string => string => bool => float = "" [@@bs.send];
    external monthsRegex : t => bool => RegExp.t = "" [@@bs.send];
    external monthsShortRegex : t => bool => RegExp.t = "" [@@bs.send];
    external week : t => Moment.t => float = "" [@@bs.send];
    external firstDayOfYear : t => float = "" [@@bs.send];
    external firstDayOfWeek : t => float = "" [@@bs.send];
    external weekdays0 : t => (array string) = "weekdays" [@@bs.send];
    external weekdays1 : t => Moment.t => string? => (unit [@bs.ignore]) => string = "weekdays" [@@bs.send];
    external weekdaysMin0 : t => (array string) = "weekdaysMin" [@@bs.send];
    external weekdaysMin1 : t => Moment.t => string = "weekdaysMin" [@@bs.send];
    external weekdaysShort0 : t => (array string) = "weekdaysShort" [@@bs.send];
    external weekdaysShort1 : t => Moment.t => string = "weekdaysShort" [@@bs.send];
    external weekdaysParse : t => string => string => bool => float = "" [@@bs.send];
    external weekdaysRegex : t => bool => RegExp.t = "" [@@bs.send];
    external weekdaysShortRegex : t => bool => RegExp.t = "" [@@bs.send];
    external weekdaysMinRegex : t => bool => RegExp.t = "" [@@bs.send];
    external isPM : t => string => bool = "" [@@bs.send];
    external meridiem : t => float => float => bool => string = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module StandaloneFormatSpec = {
    type t;

    external make : format::(array string) => standalone::(array string) => isFormat::RegExp.t? => (unit [@bs.ignore]) => t = "" [@@bs.obj];
    external setFormat : t => (array string) => unit = "format" [@@bs.set];
    external getFormat : t => (array string) = "format" [@@bs.get];

    external setStandalone : t => (array string) => unit = "standalone" [@@bs.set];
    external getStandalone : t => (array string) = "standalone" [@@bs.get];

    external setIsFormat : t => option RegExp.t => unit = "isFormat" [@@bs.set];
    external getIsFormat : t => option RegExp.t = "isFormat" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module WeekSpec = {
    type t;

    external make : dow::float => doy::float => t = "" [@@bs.obj];
    external setDow : t => float => unit = "dow" [@@bs.set];
    external getDow : t => float = "dow" [@@bs.get];

    external setDoy : t => float => unit = "doy" [@@bs.set];
    external getDoy : t => float = "doy" [@@bs.get];

  };

  let module CalendarSpecVal = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module CalendarSpec = {
    type t;

    type valueType 'a =
      | CalendarSpecValT : valueType CalendarSpecVal.t
      | Unit : valueType unit;

    external value : t => string => valueType = "" [@@bs.send];
    external make : sameDay::CalendarSpecVal.t? => nextDay::CalendarSpecVal.t? => lastDay::CalendarSpecVal.t? => nextWeek::CalendarSpecVal.t? => lastWeek::CalendarSpecVal.t? => sameElse::CalendarSpecVal.t? => (unit [@bs.ignore]) => t = "" [@@bs.obj];
    external setSameDay : t => option CalendarSpecVal.t => unit = "sameDay" [@@bs.set];
    external getSameDay : t => option CalendarSpecVal.t = "sameDay" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setNextDay : t => option CalendarSpecVal.t => unit = "nextDay" [@@bs.set];
    external getNextDay : t => option CalendarSpecVal.t = "nextDay" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLastDay : t => option CalendarSpecVal.t => unit = "lastDay" [@@bs.set];
    external getLastDay : t => option CalendarSpecVal.t = "lastDay" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setNextWeek : t => option CalendarSpecVal.t => unit = "nextWeek" [@@bs.set];
    external getNextWeek : t => option CalendarSpecVal.t = "nextWeek" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLastWeek : t => option CalendarSpecVal.t => unit = "lastWeek" [@@bs.set];
    external getLastWeek : t => option CalendarSpecVal.t = "lastWeek" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSameElse : t => option CalendarSpecVal.t => unit = "sameElse" [@@bs.set];
    external getSameElse : t => option CalendarSpecVal.t = "sameElse" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module RelativeTimeSpecVal = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module RelativeTimeFuturePastVal = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module RelativeTimeSpec = {
    type t;

    external make : future::RelativeTimeFuturePastVal.t => past::RelativeTimeFuturePastVal.t => s::RelativeTimeSpecVal.t => m::RelativeTimeSpecVal.t => mm::RelativeTimeSpecVal.t => h::RelativeTimeSpecVal.t => hh::RelativeTimeSpecVal.t => d::RelativeTimeSpecVal.t => dd::RelativeTimeSpecVal.t => M::RelativeTimeSpecVal.t => MM::RelativeTimeSpecVal.t => y::RelativeTimeSpecVal.t => yy::RelativeTimeSpecVal.t => t = "" [@@bs.obj];
    external setFuture : t => RelativeTimeFuturePastVal.t => unit = "future" [@@bs.set];
    external getFuture : t => RelativeTimeFuturePastVal.t = "future" [@@bs.get];

    external setPast : t => RelativeTimeFuturePastVal.t => unit = "past" [@@bs.set];
    external getPast : t => RelativeTimeFuturePastVal.t = "past" [@@bs.get];

    external setS : t => RelativeTimeSpecVal.t => unit = "s" [@@bs.set];
    external getS : t => RelativeTimeSpecVal.t = "s" [@@bs.get];

    external setM : t => RelativeTimeSpecVal.t => unit = "m" [@@bs.set];
    external getM : t => RelativeTimeSpecVal.t = "m" [@@bs.get];

    external setMm : t => RelativeTimeSpecVal.t => unit = "mm" [@@bs.set];
    external getMm : t => RelativeTimeSpecVal.t = "mm" [@@bs.get];

    external setH : t => RelativeTimeSpecVal.t => unit = "h" [@@bs.set];
    external getH : t => RelativeTimeSpecVal.t = "h" [@@bs.get];

    external setHh : t => RelativeTimeSpecVal.t => unit = "hh" [@@bs.set];
    external getHh : t => RelativeTimeSpecVal.t = "hh" [@@bs.get];

    external setD : t => RelativeTimeSpecVal.t => unit = "d" [@@bs.set];
    external getD : t => RelativeTimeSpecVal.t = "d" [@@bs.get];

    external setDd : t => RelativeTimeSpecVal.t => unit = "dd" [@@bs.set];
    external getDd : t => RelativeTimeSpecVal.t = "dd" [@@bs.get];

    external setM : t => RelativeTimeSpecVal.t => unit = "M" [@@bs.set];
    external getM : t => RelativeTimeSpecVal.t = "M" [@@bs.get];

    external setMM : t => RelativeTimeSpecVal.t => unit = "MM" [@@bs.set];
    external getMM : t => RelativeTimeSpecVal.t = "MM" [@@bs.get];

    external setY : t => RelativeTimeSpecVal.t => unit = "y" [@@bs.set];
    external getY : t => RelativeTimeSpecVal.t = "y" [@@bs.get];

    external setYy : t => RelativeTimeSpecVal.t => unit = "yy" [@@bs.set];
    external getYy : t => RelativeTimeSpecVal.t = "yy" [@@bs.get];

  };

  let module LongDateFormatSpec = {
    type t;

    external make : LTS::string => LT::string => L::string => LL::string => LLL::string => LLLL::string => lts::string? => lt::string? => l::string? => ll::string? => lll::string? => llll::string? => (unit [@bs.ignore]) => t = "" [@@bs.obj];
    external setLTS : t => string => unit = "LTS" [@@bs.set];
    external getLTS : t => string = "LTS" [@@bs.get];

    external setLT : t => string => unit = "LT" [@@bs.set];
    external getLT : t => string = "LT" [@@bs.get];

    external setL : t => string => unit = "L" [@@bs.set];
    external getL : t => string = "L" [@@bs.get];

    external setLL : t => string => unit = "LL" [@@bs.set];
    external getLL : t => string = "LL" [@@bs.get];

    external setLLL : t => string => unit = "LLL" [@@bs.set];
    external getLLL : t => string = "LLL" [@@bs.get];

    external setLLLL : t => string => unit = "LLLL" [@@bs.set];
    external getLLLL : t => string = "LLLL" [@@bs.get];

    external setLts : t => option string => unit = "lts" [@@bs.set];
    external getLts : t => option string = "lts" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLt : t => option string => unit = "lt" [@@bs.set];
    external getLt : t => option string = "lt" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setL : t => option string => unit = "l" [@@bs.set];
    external getL : t => option string = "l" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLl : t => option string => unit = "ll" [@@bs.set];
    external getLl : t => option string = "ll" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLll : t => option string => unit = "lll" [@@bs.set];
    external getLll : t => option string = "lll" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLlll : t => option string => unit = "llll" [@@bs.set];
    external getLlll : t => option string = "llll" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module MonthWeekdayFn = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module WeekdaySimpleFn = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module LocaleSpecification = {
    type t;

    type monthsType 'a =
      | ArrayString : monthsType (array string)
      | StandaloneFormatSpecT : monthsType StandaloneFormatSpec.t
      | MonthWeekdayFnT : monthsType MonthWeekdayFn.t;

    type monthsShortType 'a =
      | ArrayString : monthsShortType (array string)
      | StandaloneFormatSpecT : monthsShortType StandaloneFormatSpec.t
      | MonthWeekdayFnT : monthsShortType MonthWeekdayFn.t;

    type weekdaysType 'a =
      | ArrayString : weekdaysType (array string)
      | StandaloneFormatSpecT : weekdaysType StandaloneFormatSpec.t
      | MonthWeekdayFnT : weekdaysType MonthWeekdayFn.t;

    type weekdaysShortType 'a =
      | ArrayString : weekdaysShortType (array string)
      | StandaloneFormatSpecT : weekdaysShortType StandaloneFormatSpec.t
      | WeekdaySimpleFnT : weekdaysShortType WeekdaySimpleFn.t;

    type weekdaysMinType 'a =
      | ArrayString : weekdaysMinType (array string)
      | StandaloneFormatSpecT : weekdaysMinType StandaloneFormatSpec.t
      | WeekdaySimpleFnT : weekdaysMinType WeekdaySimpleFn.t;

    external value : t => string => 'Any = "" [@@bs.send];
    external make : months::monthsType? => monthsShort::monthsShortType? => weekdays::weekdaysType? => weekdaysShort::weekdaysShortType? => weekdaysMin::weekdaysMinType? => meridiemParse::RegExp.t? => meridiem::(float => float => bool => string)? => isPM::(string => bool)? => longDateFormat::LongDateFormatSpec.t? => calendar::CalendarSpec.t? => relativeTime::RelativeTimeSpec.t? => invalidDate::string? => ordinal::(float => string)? => ordinalParse::RegExp.t? => week::WeekSpec.t? => (unit [@bs.ignore]) => t = "" [@@bs.obj];
    external setMonths : t => option monthsType => unit = "months" [@@bs.set];
    external getMonths : t => option monthsType = "months" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMonthsShort : t => option monthsShortType => unit = "monthsShort" [@@bs.set];
    external getMonthsShort : t => option monthsShortType = "monthsShort" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWeekdays : t => option weekdaysType => unit = "weekdays" [@@bs.set];
    external getWeekdays : t => option weekdaysType = "weekdays" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWeekdaysShort : t => option weekdaysShortType => unit = "weekdaysShort" [@@bs.set];
    external getWeekdaysShort : t => option weekdaysShortType = "weekdaysShort" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWeekdaysMin : t => option weekdaysMinType => unit = "weekdaysMin" [@@bs.set];
    external getWeekdaysMin : t => option weekdaysMinType = "weekdaysMin" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMeridiemParse : t => option RegExp.t => unit = "meridiemParse" [@@bs.set];
    external getMeridiemParse : t => option RegExp.t = "meridiemParse" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMeridiem : t => option (float => float => bool => string) => unit = "meridiem" [@@bs.set];
    external getMeridiem : t => option (float => float => bool => string) = "meridiem" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIsPM : t => option (string => bool) => unit = "isPM" [@@bs.set];
    external getIsPM : t => option (string => bool) = "isPM" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLongDateFormat : t => option LongDateFormatSpec.t => unit = "longDateFormat" [@@bs.set];
    external getLongDateFormat : t => option LongDateFormatSpec.t = "longDateFormat" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setCalendar : t => option CalendarSpec.t => unit = "calendar" [@@bs.set];
    external getCalendar : t => option CalendarSpec.t = "calendar" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setRelativeTime : t => option RelativeTimeSpec.t => unit = "relativeTime" [@@bs.set];
    external getRelativeTime : t => option RelativeTimeSpec.t = "relativeTime" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setInvalidDate : t => option string => unit = "invalidDate" [@@bs.set];
    external getInvalidDate : t => option string = "invalidDate" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setOrdinal : t => option (float => string) => unit = "ordinal" [@@bs.set];
    external getOrdinal : t => option (float => string) = "ordinal" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setOrdinalParse : t => option RegExp.t => unit = "ordinalParse" [@@bs.set];
    external getOrdinalParse : t => option RegExp.t = "ordinalParse" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWeek : t => option WeekSpec.t => unit = "week" [@@bs.set];
    external getWeek : t => option WeekSpec.t = "week" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module MomentObjectOutput = {
    type t;

    external make : years::float => months::float => date::float => hours::float => minutes::float => seconds::float => milliseconds::float => t = "" [@@bs.obj];
    external setYears : t => float => unit = "years" [@@bs.set];
    external getYears : t => float = "years" [@@bs.get];

    external setMonths : t => float => unit = "months" [@@bs.set];
    external getMonths : t => float = "months" [@@bs.get];

    external setDate : t => float => unit = "date" [@@bs.set];
    external getDate : t => float = "date" [@@bs.get];

    external setHours : t => float => unit = "hours" [@@bs.set];
    external getHours : t => float = "hours" [@@bs.get];

    external setMinutes : t => float => unit = "minutes" [@@bs.set];
    external getMinutes : t => float = "minutes" [@@bs.get];

    external setSeconds : t => float => unit = "seconds" [@@bs.set];
    external getSeconds : t => float = "seconds" [@@bs.get];

    external setMilliseconds : t => float => unit = "milliseconds" [@@bs.set];
    external getMilliseconds : t => float = "milliseconds" [@@bs.get];

  };

  let module Duration = {
    type t;

    external humanize : t => bool? => (unit [@bs.ignore]) => string = "" [@@bs.send];
    external abs : t => Duration.t = "" [@@bs.send];
    external as : t => unitOfTime.Base.t => float = "" [@@bs.send];
    external get : t => unitOfTime.Base.t => float = "" [@@bs.send];
    external milliseconds : t => float = "" [@@bs.send];
    external asMilliseconds : t => float = "" [@@bs.send];
    external seconds : t => float = "" [@@bs.send];
    external asSeconds : t => float = "" [@@bs.send];
    external minutes : t => float = "" [@@bs.send];
    external asMinutes : t => float = "" [@@bs.send];
    external hours : t => float = "" [@@bs.send];
    external asHours : t => float = "" [@@bs.send];
    external days : t => float = "" [@@bs.send];
    external asDays : t => float = "" [@@bs.send];
    external weeks : t => float = "" [@@bs.send];
    external asWeeks : t => float = "" [@@bs.send];
    external months : t => float = "" [@@bs.send];
    external asMonths : t => float = "" [@@bs.send];
    external years : t => float = "" [@@bs.send];
    external asYears : t => float = "" [@@bs.send];
    external add : t => DurationInputArg1.t? => DurationInputArg2.t? => (unit [@bs.ignore]) => Duration.t = "" [@@bs.send];
    external subtract : t => DurationInputArg1.t? => DurationInputArg2.t? => (unit [@bs.ignore]) => Duration.t = "" [@@bs.send];
    external locale0 : t => string = "locale" [@@bs.send];
    external locale1 : t => LocaleSpecifier.t => Duration.t = "locale" [@@bs.send];
    external localeData : t => Locale.t = "" [@@bs.send];
    external toISOString : t => string = "" [@@bs.send];
    external toJSON : t => string = "" [@@bs.send];
    external lang0 : t => LocaleSpecifier.t => Moment.t = "lang" [@@bs.send];
    external lang1 : t => Locale.t = "lang" [@@bs.send];
    external toIsoString : t => string = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module MomentRelativeTime = {
    type t;

    external make : future::'Any => past::'Any => s::'Any => m::'Any => mm::'Any => h::'Any => hh::'Any => d::'Any => dd::'Any => M::'Any => MM::'Any => y::'Any => yy::'Any => t = "" [@@bs.obj];
    external setFuture : t => 'Any => unit = "future" [@@bs.set];
    external getFuture : t => 'Any = "future" [@@bs.get];

    external setPast : t => 'Any => unit = "past" [@@bs.set];
    external getPast : t => 'Any = "past" [@@bs.get];

    external setS : t => 'Any => unit = "s" [@@bs.set];
    external getS : t => 'Any = "s" [@@bs.get];

    external setM : t => 'Any => unit = "m" [@@bs.set];
    external getM : t => 'Any = "m" [@@bs.get];

    external setMm : t => 'Any => unit = "mm" [@@bs.set];
    external getMm : t => 'Any = "mm" [@@bs.get];

    external setH : t => 'Any => unit = "h" [@@bs.set];
    external getH : t => 'Any = "h" [@@bs.get];

    external setHh : t => 'Any => unit = "hh" [@@bs.set];
    external getHh : t => 'Any = "hh" [@@bs.get];

    external setD : t => 'Any => unit = "d" [@@bs.set];
    external getD : t => 'Any = "d" [@@bs.get];

    external setDd : t => 'Any => unit = "dd" [@@bs.set];
    external getDd : t => 'Any = "dd" [@@bs.get];

    external setM : t => 'Any => unit = "M" [@@bs.set];
    external getM : t => 'Any = "M" [@@bs.get];

    external setMM : t => 'Any => unit = "MM" [@@bs.set];
    external getMM : t => 'Any = "MM" [@@bs.get];

    external setY : t => 'Any => unit = "y" [@@bs.set];
    external getY : t => 'Any = "y" [@@bs.get];

    external setYy : t => 'Any => unit = "yy" [@@bs.set];
    external getYy : t => 'Any = "yy" [@@bs.get];

  };

  let module MomentLongDateFormat = {
    type t;

    external make : L::string => LL::string => LLL::string => LLLL::string => LT::string => LTS::string => l::string? => ll::string? => lll::string? => llll::string? => lt::string? => lts::string? => (unit [@bs.ignore]) => t = "" [@@bs.obj];
    external setL : t => string => unit = "L" [@@bs.set];
    external getL : t => string = "L" [@@bs.get];

    external setLL : t => string => unit = "LL" [@@bs.set];
    external getLL : t => string = "LL" [@@bs.get];

    external setLLL : t => string => unit = "LLL" [@@bs.set];
    external getLLL : t => string = "LLL" [@@bs.get];

    external setLLLL : t => string => unit = "LLLL" [@@bs.set];
    external getLLLL : t => string = "LLLL" [@@bs.get];

    external setLT : t => string => unit = "LT" [@@bs.set];
    external getLT : t => string = "LT" [@@bs.get];

    external setLTS : t => string => unit = "LTS" [@@bs.set];
    external getLTS : t => string = "LTS" [@@bs.get];

    external setL : t => option string => unit = "l" [@@bs.set];
    external getL : t => option string = "l" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLl : t => option string => unit = "ll" [@@bs.set];
    external getLl : t => option string = "ll" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLll : t => option string => unit = "lll" [@@bs.set];
    external getLll : t => option string = "lll" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLlll : t => option string => unit = "llll" [@@bs.set];
    external getLlll : t => option string = "llll" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLt : t => option string => unit = "lt" [@@bs.set];
    external getLt : t => option string = "lt" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLts : t => option string => unit = "lts" [@@bs.set];
    external getLts : t => option string = "lts" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module MomentParsingFlags = {
    type t;

    type invalidMonthType 'a =
      | String : invalidMonthType string
      | Unit : invalidMonthType unit;

    type meridiemType 'a =
      | String : meridiemType string
      | Unit : meridiemType unit;

    external make : empty::bool => unusedTokens::(array string) => unusedInput::(array string) => overflow::float => charsLeftOver::float => nullInput::bool => invalidMonth::invalidMonthType => invalidFormat::bool => userInvalidated::bool => iso::bool => parsedDateParts::(array 'Any) => meridiem::meridiemType => t = "" [@@bs.obj];
    external setEmpty : t => bool => unit = "empty" [@@bs.set];
    external getEmpty : t => bool = "empty" [@@bs.get];

    external setUnusedTokens : t => (array string) => unit = "unusedTokens" [@@bs.set];
    external getUnusedTokens : t => (array string) = "unusedTokens" [@@bs.get];

    external setUnusedInput : t => (array string) => unit = "unusedInput" [@@bs.set];
    external getUnusedInput : t => (array string) = "unusedInput" [@@bs.get];

    external setOverflow : t => float => unit = "overflow" [@@bs.set];
    external getOverflow : t => float = "overflow" [@@bs.get];

    external setCharsLeftOver : t => float => unit = "charsLeftOver" [@@bs.set];
    external getCharsLeftOver : t => float = "charsLeftOver" [@@bs.get];

    external setNullInput : t => bool => unit = "nullInput" [@@bs.set];
    external getNullInput : t => bool = "nullInput" [@@bs.get];

    external setInvalidMonth : t => invalidMonthType => unit = "invalidMonth" [@@bs.set];
    external getInvalidMonth : t => invalidMonthType = "invalidMonth" [@@bs.get];

    external setInvalidFormat : t => bool => unit = "invalidFormat" [@@bs.set];
    external getInvalidFormat : t => bool = "invalidFormat" [@@bs.get];

    external setUserInvalidated : t => bool => unit = "userInvalidated" [@@bs.set];
    external getUserInvalidated : t => bool = "userInvalidated" [@@bs.get];

    external setIso : t => bool => unit = "iso" [@@bs.set];
    external getIso : t => bool = "iso" [@@bs.get];

    external setParsedDateParts : t => (array 'Any) => unit = "parsedDateParts" [@@bs.set];
    external getParsedDateParts : t => (array 'Any) = "parsedDateParts" [@@bs.get];

    external setMeridiem : t => meridiemType => unit = "meridiem" [@@bs.set];
    external getMeridiem : t => meridiemType = "meridiem" [@@bs.get];

  };

  let module MomentParsingFlagsOpt = {
    type t;

    external make : empty::bool? => unusedTokens::(array string)? => unusedInput::(array string)? => overflow::float? => charsLeftOver::float? => nullInput::bool? => invalidMonth::string? => invalidFormat::bool? => userInvalidated::bool? => iso::bool? => parsedDateParts::(array 'Any)? => meridiem::string? => (unit [@bs.ignore]) => t = "" [@@bs.obj];
    external setEmpty : t => option bool => unit = "empty" [@@bs.set];
    external getEmpty : t => option bool = "empty" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setUnusedTokens : t => option (array string) => unit = "unusedTokens" [@@bs.set];
    external getUnusedTokens : t => option (array string) = "unusedTokens" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setUnusedInput : t => option (array string) => unit = "unusedInput" [@@bs.set];
    external getUnusedInput : t => option (array string) = "unusedInput" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setOverflow : t => option float => unit = "overflow" [@@bs.set];
    external getOverflow : t => option float = "overflow" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setCharsLeftOver : t => option float => unit = "charsLeftOver" [@@bs.set];
    external getCharsLeftOver : t => option float = "charsLeftOver" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setNullInput : t => option bool => unit = "nullInput" [@@bs.set];
    external getNullInput : t => option bool = "nullInput" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setInvalidMonth : t => option string => unit = "invalidMonth" [@@bs.set];
    external getInvalidMonth : t => option string = "invalidMonth" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setInvalidFormat : t => option bool => unit = "invalidFormat" [@@bs.set];
    external getInvalidFormat : t => option bool = "invalidFormat" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setUserInvalidated : t => option bool => unit = "userInvalidated" [@@bs.set];
    external getUserInvalidated : t => option bool = "userInvalidated" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIso : t => option bool => unit = "iso" [@@bs.set];
    external getIso : t => option bool = "iso" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setParsedDateParts : t => option (array 'Any) => unit = "parsedDateParts" [@@bs.set];
    external getParsedDateParts : t => option (array 'Any) = "parsedDateParts" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMeridiem : t => option string => unit = "meridiem" [@@bs.set];
    external getMeridiem : t => option string = "meridiem" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module MomentBuiltinFormat = {
    type t;

    external make : ___momentBuiltinFormatBrand::'Any => t = "" [@@bs.obj];
    external set___momentBuiltinFormatBrand : t => 'Any => unit = "___momentBuiltinFormatBrand" [@@bs.set];
    external get___momentBuiltinFormatBrand : t => 'Any = "___momentBuiltinFormatBrand" [@@bs.get];

  };

  let module MomentFormatSpecification = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module MomentInputObject = {
    type t;

    external make : years::float? => year::float? => y::float? => months::float? => month::float? => M::float? => days::float? => day::float? => d::float? => dates::float? => date::float? => D::float? => hours::float? => hour::float? => h::float? => minutes::float? => minute::float? => m::float? => seconds::float? => second::float? => s::float? => milliseconds::float? => millisecond::float? => ms::float? => (unit [@bs.ignore]) => t = "" [@@bs.obj];
    external setYears : t => option float => unit = "years" [@@bs.set];
    external getYears : t => option float = "years" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setYear : t => option float => unit = "year" [@@bs.set];
    external getYear : t => option float = "year" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setY : t => option float => unit = "y" [@@bs.set];
    external getY : t => option float = "y" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMonths : t => option float => unit = "months" [@@bs.set];
    external getMonths : t => option float = "months" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMonth : t => option float => unit = "month" [@@bs.set];
    external getMonth : t => option float = "month" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setM : t => option float => unit = "M" [@@bs.set];
    external getM : t => option float = "M" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDays : t => option float => unit = "days" [@@bs.set];
    external getDays : t => option float = "days" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDay : t => option float => unit = "day" [@@bs.set];
    external getDay : t => option float = "day" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setD : t => option float => unit = "d" [@@bs.set];
    external getD : t => option float = "d" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDates : t => option float => unit = "dates" [@@bs.set];
    external getDates : t => option float = "dates" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDate : t => option float => unit = "date" [@@bs.set];
    external getDate : t => option float = "date" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setD : t => option float => unit = "D" [@@bs.set];
    external getD : t => option float = "D" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHours : t => option float => unit = "hours" [@@bs.set];
    external getHours : t => option float = "hours" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setHour : t => option float => unit = "hour" [@@bs.set];
    external getHour : t => option float = "hour" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setH : t => option float => unit = "h" [@@bs.set];
    external getH : t => option float = "h" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMinutes : t => option float => unit = "minutes" [@@bs.set];
    external getMinutes : t => option float = "minutes" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMinute : t => option float => unit = "minute" [@@bs.set];
    external getMinute : t => option float = "minute" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setM : t => option float => unit = "m" [@@bs.set];
    external getM : t => option float = "m" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSeconds : t => option float => unit = "seconds" [@@bs.set];
    external getSeconds : t => option float = "seconds" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setSecond : t => option float => unit = "second" [@@bs.set];
    external getSecond : t => option float = "second" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setS : t => option float => unit = "s" [@@bs.set];
    external getS : t => option float = "s" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMilliseconds : t => option float => unit = "milliseconds" [@@bs.set];
    external getMilliseconds : t => option float = "milliseconds" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMillisecond : t => option float => unit = "millisecond" [@@bs.set];
    external getMillisecond : t => option float = "millisecond" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setMs : t => option float => unit = "ms" [@@bs.set];
    external getMs : t => option float = "ms" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module DurationInputObject = {
    type t;

    external make : quarters::float? => quarter::float? => Q::float? => weeks::float? => week::float? => w::float? => (unit [@bs.ignore]) => t = "" [@@bs.obj];
    external setQuarters : t => option float => unit = "quarters" [@@bs.set];
    external getQuarters : t => option float = "quarters" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setQuarter : t => option float => unit = "quarter" [@@bs.set];
    external getQuarter : t => option float = "quarter" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setQ : t => option float => unit = "Q" [@@bs.set];
    external getQ : t => option float = "Q" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWeeks : t => option float => unit = "weeks" [@@bs.set];
    external getWeeks : t => option float = "weeks" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWeek : t => option float => unit = "week" [@@bs.set];
    external getWeek : t => option float = "week" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setW : t => option float => unit = "w" [@@bs.set];
    external getW : t => option float = "w" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module MomentSetObject = {
    type t;

    external make : weekYears::float? => weekYear::float? => gg::float? => isoWeekYears::float? => isoWeekYear::float? => GG::float? => quarters::float? => quarter::float? => Q::float? => weeks::float? => week::float? => w::float? => isoWeeks::float? => isoWeek::float? => W::float? => dayOfYears::float? => dayOfYear::float? => DDD::float? => weekdays::float? => weekday::float? => e::float? => isoWeekdays::float? => isoWeekday::float? => E::float? => (unit [@bs.ignore]) => t = "" [@@bs.obj];
    external setWeekYears : t => option float => unit = "weekYears" [@@bs.set];
    external getWeekYears : t => option float = "weekYears" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWeekYear : t => option float => unit = "weekYear" [@@bs.set];
    external getWeekYear : t => option float = "weekYear" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setGg : t => option float => unit = "gg" [@@bs.set];
    external getGg : t => option float = "gg" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIsoWeekYears : t => option float => unit = "isoWeekYears" [@@bs.set];
    external getIsoWeekYears : t => option float = "isoWeekYears" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIsoWeekYear : t => option float => unit = "isoWeekYear" [@@bs.set];
    external getIsoWeekYear : t => option float = "isoWeekYear" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setGG : t => option float => unit = "GG" [@@bs.set];
    external getGG : t => option float = "GG" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setQuarters : t => option float => unit = "quarters" [@@bs.set];
    external getQuarters : t => option float = "quarters" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setQuarter : t => option float => unit = "quarter" [@@bs.set];
    external getQuarter : t => option float = "quarter" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setQ : t => option float => unit = "Q" [@@bs.set];
    external getQ : t => option float = "Q" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWeeks : t => option float => unit = "weeks" [@@bs.set];
    external getWeeks : t => option float = "weeks" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWeek : t => option float => unit = "week" [@@bs.set];
    external getWeek : t => option float = "week" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setW : t => option float => unit = "w" [@@bs.set];
    external getW : t => option float = "w" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIsoWeeks : t => option float => unit = "isoWeeks" [@@bs.set];
    external getIsoWeeks : t => option float = "isoWeeks" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIsoWeek : t => option float => unit = "isoWeek" [@@bs.set];
    external getIsoWeek : t => option float = "isoWeek" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setW : t => option float => unit = "W" [@@bs.set];
    external getW : t => option float = "W" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDayOfYears : t => option float => unit = "dayOfYears" [@@bs.set];
    external getDayOfYears : t => option float = "dayOfYears" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDayOfYear : t => option float => unit = "dayOfYear" [@@bs.set];
    external getDayOfYear : t => option float = "dayOfYear" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setDDD : t => option float => unit = "DDD" [@@bs.set];
    external getDDD : t => option float = "DDD" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWeekdays : t => option float => unit = "weekdays" [@@bs.set];
    external getWeekdays : t => option float = "weekdays" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setWeekday : t => option float => unit = "weekday" [@@bs.set];
    external getWeekday : t => option float = "weekday" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setE : t => option float => unit = "e" [@@bs.set];
    external getE : t => option float = "e" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIsoWeekdays : t => option float => unit = "isoWeekdays" [@@bs.set];
    external getIsoWeekdays : t => option float = "isoWeekdays" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setIsoWeekday : t => option float => unit = "isoWeekday" [@@bs.set];
    external getIsoWeekday : t => option float = "isoWeekday" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setE : t => option float => unit = "E" [@@bs.set];
    external getE : t => option float = "E" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module FromTo = {
    type t;

    external make : from::MomentInput.t => to::MomentInput.t => t = "" [@@bs.obj];
    external setFrom : t => MomentInput.t => unit = "from" [@@bs.set];
    external getFrom : t => MomentInput.t = "from" [@@bs.get];

    external setTo : t => MomentInput.t => unit = "to" [@@bs.set];
    external getTo : t => MomentInput.t = "to" [@@bs.get];

  };

  let module MomentInput = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module DurationInputArg1 = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module DurationInputArg2 = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module LocaleSpecifier = {
    type t;

    external make : unit => t = "" [@@bs.obj];
  };

  let module MomentCreationData = {
    type t;

    external make : input::MomentInput.t => format::MomentFormatSpecification.t? => locale::Locale.t => isUTC::bool => strict::bool? => (unit [@bs.ignore]) => t = "" [@@bs.obj];
    external setInput : t => MomentInput.t => unit = "input" [@@bs.set];
    external getInput : t => MomentInput.t = "input" [@@bs.get];

    external setFormat : t => option MomentFormatSpecification.t => unit = "format" [@@bs.set];
    external getFormat : t => option MomentFormatSpecification.t = "format" [@@bs.get] [@@bs.return null_undefined_to_opt];

    external setLocale : t => Locale.t => unit = "locale" [@@bs.set];
    external getLocale : t => Locale.t = "locale" [@@bs.get];

    external setIsUTC : t => bool => unit = "isUTC" [@@bs.set];
    external getIsUTC : t => bool = "isUTC" [@@bs.get];

    external setStrict : t => option bool => unit = "strict" [@@bs.set];
    external getStrict : t => option bool = "strict" [@@bs.get] [@@bs.return null_undefined_to_opt];

  };

  let module Moment = {
    type t;

    type amountType 'a =
      | Float : amountType float
      | String : amountType string;

    type amountType 'a =
      | Float : amountType float
      | String : amountType string;

    type mType 'a =
      | Float : mType float
      | String : mType string;

    type mType 'a =
      | Float : mType float
      | String : mType string;

    type dType 'a =
      | Float : dType float
      | String : dType string;

    type dType 'a =
      | Float : dType float
      | String : dType string;

    type dType 'a =
      | Float : dType float
      | String : dType string;

    type bType 'a =
      | Float : bType float
      | String : bType string;

    type bType 'a =
      | Float : bType float
      | String : bType string;

    type inclusivityType 'a =
      | String : inclusivityType string
      | String : inclusivityType string
      | String : inclusivityType string
      | String : inclusivityType string;

    external format : t => string? => (unit [@bs.ignore]) => string = "" [@@bs.send];
    external startOf : t => unitOfTime.StartOf.t => Moment.t = "" [@@bs.send];
    external endOf : t => unitOfTime.StartOf.t => Moment.t = "" [@@bs.send];
    external add0 : t => DurationInputArg1.t? => DurationInputArg2.t? => (unit [@bs.ignore]) => Moment.t = "add" [@@bs.send];
    external add1 : t => unitOfTime.DurationConstructor.t => (amountType 'a [@bs.ignore]) => 'a => Moment.t = "add" [@@bs.send];
    external subtract0 : t => DurationInputArg1.t? => DurationInputArg2.t? => (unit [@bs.ignore]) => Moment.t = "subtract" [@@bs.send];
    external subtract1 : t => unitOfTime.DurationConstructor.t => (amountType 'a [@bs.ignore]) => 'a => Moment.t = "subtract" [@@bs.send];
    external calendar : t => MomentInput.t? => CalendarSpec.t? => (unit [@bs.ignore]) => string = "" [@@bs.send];
    external clone : t => Moment.t = "" [@@bs.send];
    external valueOf : t => float = "" [@@bs.send];
    external local : t => bool? => (unit [@bs.ignore]) => Moment.t = "" [@@bs.send];
    external isLocal : t => bool = "" [@@bs.send];
    external utc : t => bool? => (unit [@bs.ignore]) => Moment.t = "" [@@bs.send];
    external isUTC : t => bool = "" [@@bs.send];
    external isUtc : t => bool = "" [@@bs.send];
    external parseZone : t => Moment.t = "" [@@bs.send];
    external isValid : t => bool = "" [@@bs.send];
    external invalidAt : t => float = "" [@@bs.send];
    external hasAlignedHourOffset : t => MomentInput.t? => (unit [@bs.ignore]) => bool = "" [@@bs.send];
    external creationData : t => MomentCreationData.t = "" [@@bs.send];
    external parsingFlags : t => MomentParsingFlags.t = "" [@@bs.send];
    external year0 : t => float => Moment.t = "year" [@@bs.send];
    external year1 : t => float = "year" [@@bs.send];
    external years0 : t => float => Moment.t = "years" [@@bs.send];
    external years1 : t => float = "years" [@@bs.send];
    external quarter0 : t => float = "quarter" [@@bs.send];
    external quarter1 : t => float => Moment.t = "quarter" [@@bs.send];
    external quarters0 : t => float = "quarters" [@@bs.send];
    external quarters1 : t => float => Moment.t = "quarters" [@@bs.send];
    external month0 : t => (mType 'a [@bs.ignore]) => 'a => Moment.t = "month" [@@bs.send];
    external month1 : t => float = "month" [@@bs.send];
    external months0 : t => (mType 'a [@bs.ignore]) => 'a => Moment.t = "months" [@@bs.send];
    external months1 : t => float = "months" [@@bs.send];
    external day0 : t => (dType 'a [@bs.ignore]) => 'a => Moment.t = "day" [@@bs.send];
    external day1 : t => float = "day" [@@bs.send];
    external days0 : t => (dType 'a [@bs.ignore]) => 'a => Moment.t = "days" [@@bs.send];
    external days1 : t => float = "days" [@@bs.send];
    external date0 : t => float => Moment.t = "date" [@@bs.send];
    external date1 : t => float = "date" [@@bs.send];
    external dates0 : t => float => Moment.t = "dates" [@@bs.send];
    external dates1 : t => float = "dates" [@@bs.send];
    external hour0 : t => float => Moment.t = "hour" [@@bs.send];
    external hour1 : t => float = "hour" [@@bs.send];
    external hours0 : t => float => Moment.t = "hours" [@@bs.send];
    external hours1 : t => float = "hours" [@@bs.send];
    external minute0 : t => float => Moment.t = "minute" [@@bs.send];
    external minute1 : t => float = "minute" [@@bs.send];
    external minutes0 : t => float => Moment.t = "minutes" [@@bs.send];
    external minutes1 : t => float = "minutes" [@@bs.send];
    external second0 : t => float => Moment.t = "second" [@@bs.send];
    external second1 : t => float = "second" [@@bs.send];
    external seconds0 : t => float => Moment.t = "seconds" [@@bs.send];
    external seconds1 : t => float = "seconds" [@@bs.send];
    external millisecond0 : t => float => Moment.t = "millisecond" [@@bs.send];
    external millisecond1 : t => float = "millisecond" [@@bs.send];
    external milliseconds0 : t => float => Moment.t = "milliseconds" [@@bs.send];
    external milliseconds1 : t => float = "milliseconds" [@@bs.send];
    external weekday0 : t => float = "weekday" [@@bs.send];
    external weekday1 : t => float => Moment.t = "weekday" [@@bs.send];
    external isoWeekday0 : t => float = "isoWeekday" [@@bs.send];
    external isoWeekday1 : t => (dType 'a [@bs.ignore]) => 'a => Moment.t = "isoWeekday" [@@bs.send];
    external weekYear0 : t => float = "weekYear" [@@bs.send];
    external weekYear1 : t => float => Moment.t = "weekYear" [@@bs.send];
    external isoWeekYear0 : t => float = "isoWeekYear" [@@bs.send];
    external isoWeekYear1 : t => float => Moment.t = "isoWeekYear" [@@bs.send];
    external week0 : t => float = "week" [@@bs.send];
    external week1 : t => float => Moment.t = "week" [@@bs.send];
    external weeks0 : t => float = "weeks" [@@bs.send];
    external weeks1 : t => float => Moment.t = "weeks" [@@bs.send];
    external isoWeek0 : t => float = "isoWeek" [@@bs.send];
    external isoWeek1 : t => float => Moment.t = "isoWeek" [@@bs.send];
    external isoWeeks0 : t => float = "isoWeeks" [@@bs.send];
    external isoWeeks1 : t => float => Moment.t = "isoWeeks" [@@bs.send];
    external weeksInYear : t => float = "" [@@bs.send];
    external isoWeeksInYear : t => float = "" [@@bs.send];
    external dayOfYear0 : t => float = "dayOfYear" [@@bs.send];
    external dayOfYear1 : t => float => Moment.t = "dayOfYear" [@@bs.send];
    external from : t => MomentInput.t => bool? => (unit [@bs.ignore]) => string = "" [@@bs.send];
    external to : t => MomentInput.t => bool? => (unit [@bs.ignore]) => string = "" [@@bs.send];
    external fromNow : t => bool? => (unit [@bs.ignore]) => string = "" [@@bs.send];
    external toNow : t => bool? => (unit [@bs.ignore]) => string = "" [@@bs.send];
    external diff : t => MomentInput.t => unitOfTime.Diff.t? => bool? => (unit [@bs.ignore]) => float = "" [@@bs.send];
    external toArray : t => (array float) = "" [@@bs.send];
    external toDate : t => Date.t = "" [@@bs.send];
    external toISOString : t => string = "" [@@bs.send];
    external inspect : t => string = "" [@@bs.send];
    external toJSON : t => string = "" [@@bs.send];
    external unix : t => float = "" [@@bs.send];
    external isLeapYear : t => bool = "" [@@bs.send];
    external zone0 : t => float = "zone" [@@bs.send];
    external zone1 : t => (bType 'a [@bs.ignore]) => 'a => Moment.t = "zone" [@@bs.send];
    external utcOffset0 : t => float = "utcOffset" [@@bs.send];
    external utcOffset1 : t => (bType 'a [@bs.ignore]) => 'a => bool? => (unit [@bs.ignore]) => Moment.t = "utcOffset" [@@bs.send];
    external isUtcOffset : t => bool = "" [@@bs.send];
    external daysInMonth : t => float = "" [@@bs.send];
    external isDST : t => bool = "" [@@bs.send];
    external zoneAbbr : t => string = "" [@@bs.send];
    external zoneName : t => string = "" [@@bs.send];
    external isBefore : t => MomentInput.t? => unitOfTime.StartOf.t? => (unit [@bs.ignore]) => bool = "" [@@bs.send];
    external isAfter : t => MomentInput.t? => unitOfTime.StartOf.t? => (unit [@bs.ignore]) => bool = "" [@@bs.send];
    external isSame : t => MomentInput.t? => unitOfTime.StartOf.t? => (unit [@bs.ignore]) => bool = "" [@@bs.send];
    external isSameOrAfter : t => MomentInput.t? => unitOfTime.StartOf.t? => (unit [@bs.ignore]) => bool = "" [@@bs.send];
    external isSameOrBefore : t => MomentInput.t? => unitOfTime.StartOf.t? => (unit [@bs.ignore]) => bool = "" [@@bs.send];
    external isBetween : t => MomentInput.t => MomentInput.t => unitOfTime.StartOf.t? => (inclusivityType 'a [@bs.ignore]) => 'a? => (unit [@bs.ignore]) => bool = "" [@@bs.send];
    external lang0 : t => LocaleSpecifier.t => Moment.t = "lang" [@@bs.send];
    external lang1 : t => Locale.t = "lang" [@@bs.send];
    external locale0 : t => string = "locale" [@@bs.send];
    external locale1 : t => LocaleSpecifier.t => Moment.t = "locale" [@@bs.send];
    external localeData : t => Locale.t = "" [@@bs.send];
    external isDSTShifted : t => bool = "" [@@bs.send];
    external max0 : t => MomentInput.t? => MomentFormatSpecification.t? => bool? => (unit [@bs.ignore]) => Moment.t = "max" [@@bs.send];
    external max1 : t => MomentInput.t? => MomentFormatSpecification.t? => string? => bool? => (unit [@bs.ignore]) => Moment.t = "max" [@@bs.send];
    external min0 : t => MomentInput.t? => MomentFormatSpecification.t? => bool? => (unit [@bs.ignore]) => Moment.t = "min" [@@bs.send];
    external min1 : t => MomentInput.t? => MomentFormatSpecification.t? => string? => bool? => (unit [@bs.ignore]) => Moment.t = "min" [@@bs.send];
    external get : t => unitOfTime.All.t => float = "" [@@bs.send];
    external set0 : t => unitOfTime.All.t => float => Moment.t = "set" [@@bs.send];
    external set1 : t => MomentSetObject.t => Moment.t = "set" [@@bs.send];
    external toObject : t => MomentObjectOutput.t = "" [@@bs.send];
    external make : unit => t = "" [@@bs.obj];
  };

  let module UnitOfTime = {

    let module Base = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module _quarter = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module _isoWeek = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module _date = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module DurationConstructor = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module DurationAs = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module StartOf = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module Diff = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module MomentConstructor = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

    let module All = {
      type t;

      external make : unit => t = "" [@@bs.obj];
    };

  };

};

