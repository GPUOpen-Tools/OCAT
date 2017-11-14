<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
xmlns:wix="http://schemas.microsoft.com/wix/2006/wi">
  <xsl:output method="xml" indent="yes" />
  <xsl:template match="@*|node()">
    <xsl:copy>
      <xsl:apply-templates select="@*|node()"/>
    </xsl:copy>
  </xsl:template>
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, '.pdb')]" use="@Id" />
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, '.xml')]" use="@Id" />
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, '.ilk')]" use="@Id" />
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, '.lib')]" use="@Id" />
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, '.exp')]" use="@Id" />
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, '.ini')]" use="@Id" />
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, '.iobj')]" use="@Id" />
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, '.ipdb')]" use="@Id" />
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, '.dll.metagen')]" use="@Id" />
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, '.dll.config')]" use="@Id" />
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, '.vshost.exe')]" use="@Id" />
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, 'app.config')]" use="@Id" />
  <xsl:key name="search" match="wix:Component[contains(wix:File/@Source, '.json')]" use="@Id" />
  <xsl:key name="search" match="wix:Directory[not(contains(@Name, 'Bin'))]/wix:Component" use="@Id"/>
  <xsl:key name="search" match="wix:Directory[not(contains(@Name, 'Bin'))]" use="@Id"/>
  <xsl:template match="wix:Component[key('search', @Id)]" />
  <xsl:template match="wix:ComponentRef[key('search', @Id)]"/> 
  <xsl:template match="wix:Directory[key('search', @Id)]" />
</xsl:stylesheet>