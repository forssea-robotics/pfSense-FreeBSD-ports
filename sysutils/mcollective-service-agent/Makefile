PORTNAME=	mcollective-service-agent

COMMENT=	MCollective agent to manage the OS Services

# See MASTERDIR for MAINTAINER.

DEPRECATED=	Depends on broken sysutils/mcollective
EXPIRATION_DATE=	2023-06-30

RUN_DEPENDS=	mcollective-service-common>=${PORTVERSION}:sysutils/mcollective-service-common

MASTERDIR=	${.CURDIR}/../mcollective-service-common

PLIST_FILES=	share/mcollective/agent/service.rb

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "agent/*.rb" ${STAGEDIR}${PREFIX}/share/mcollective

.include "${MASTERDIR}/Makefile"
