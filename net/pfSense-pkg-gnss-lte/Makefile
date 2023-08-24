# $FreeBSD$

PORTNAME=	pfSense-pkg-gnss-lte
PORTREVISION=	1.18.4
CATEGORIES=	net
MASTER_SITES=   # empty
DISTFILES=      # empty
EXTRACT_ONLY=   # empty

MAINTAINER=	epolge@forssea-robotics.fr
COMMENT=	GNSS_LTE port

RUN_DEPENDS=    # empty

NO_BUILD=       yes
NO_MTREE=       yes

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	PORTNAME=${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/pkg
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}${PREFIX}/pkg/gnss_lte.xml \
		${STAGEDIR}${PREFIX}/pkg
	${INSTALL_DATA} ${FILESDIR}${PREFIX}/pkg/gnss_lte.inc \
		${STAGEDIR}${PREFIX}/pkg
	${INSTALL_DATA} -m 0755 ${FILESDIR}${PREFIX}/bin/gnss_lte.yml \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} -m 0755 ${FILESDIR}${PREFIX}/bin/frs_gnss_init.sh \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}${DATADIR}/info.xml \
		${STAGEDIR}${DATADIR}
	@${REINPLACE_CMD} -i '' -e "s|%%PKGVERSION%%|${PKGVERSION}|" \
		${STAGEDIR}${PREFIX}/pkg/gnss_lte.xml \
		${STAGEDIR}${DATADIR}/info.xml

.include <bsd.port.mk>
